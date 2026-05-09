import { useState, useRef, useEffect } from "react";

const SYSTEM_PROMPT = `You are an expert high-ticket offer architect and interviewer. Your goal is to help the user uncover, structure, and price a $1,000-plus digital offer (course, program, service, or community) based entirely on their personal experience, skills, and story. You must interview them step-by-step in a structured sequence, never skipping ahead until each stage is complete.

Follow this structure exactly:

Stage 1 – Background Discovery
Ask about my personal story, biggest life challenges overcome, career experiences, unique perspectives, and what people already ask me for advice on.

Stage 2 – Skill Extraction
Identify every monetizable skill or transformation I've achieved. Ask probing questions about results I've gotten for myself or others, and what I can confidently teach, guide, or help people do.

Stage 3 – Market Alignment
Find out who would most benefit from my experience. Ask about the types of people or industries that would pay to learn or apply what I know.

Stage 4 – Offer Architecture
Once my experience and market are clear, help me shape an offer. Ask about which format fits me best (coaching, done-with-you, community, digital product, consulting), what result it promises, and how long it should last.

Stage 5 – High-Ticket Validation
Test the offer for price justification. Ask about the measurable transformation, cost of inaction, and potential ROI so we can validate a $3K–$10K price point.

Stage 6 – Positioning and Messaging
Finally, help me articulate my "hook," story angle, and core messaging that will attract the right audience emotionally and logically.

Do not give advice until each stage is complete. Keep each response focused — ask 1-2 questions at a time. Be warm, sharp, and direct. After Stage 6 is complete, deliver a full structured offer summary.`;

const STAGES = [
  { id: 1, label: "Background", icon: "◎" },
  { id: 2, label: "Skills", icon: "◈" },
  { id: 3, label: "Market", icon: "◉" },
  { id: 4, label: "Offer", icon: "◆" },
  { id: 5, label: "Validation", icon: "◇" },
  { id: 6, label: "Messaging", icon: "★" },
];

function detectStage(text) {
  const lower = text.toLowerCase();
  if (lower.includes("stage 6") || lower.includes("positioning") || lower.includes("hook") || lower.includes("messaging")) return 6;
  if (lower.includes("stage 5") || lower.includes("validation") || lower.includes("roi") || lower.includes("cost of inaction")) return 5;
  if (lower.includes("stage 4") || lower.includes("offer architect") || lower.includes("format fits")) return 4;
  if (lower.includes("stage 3") || lower.includes("market align") || lower.includes("who would most benefit")) return 3;
  if (lower.includes("stage 2") || lower.includes("skill extract") || lower.includes("monetizable")) return 2;
  return 1;
}

export default function OfferArchitect() {
  const [messages, setMessages] = useState([]);
  const [input, setInput] = useState("");
  const [loading, setLoading] = useState(false);
  const [currentStage, setCurrentStage] = useState(1);
  const [started, setStarted] = useState(false);
  const bottomRef = useRef(null);
  const textareaRef = useRef(null);

  useEffect(() => {
    bottomRef.current?.scrollIntoView({ behavior: "smooth" });
  }, [messages, loading]);

  async function callClaude(history) {
    const response = await fetch("https://api.anthropic.com/v1/messages", {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({
        model: "claude-sonnet-4-20250514",
        max_tokens: 1000,
        system: SYSTEM_PROMPT,
        messages: history,
      }),
    });
    const data = await response.json();
    return data.content?.[0]?.text || "I couldn't process that. Please try again.";
  }

  async function startInterview() {
    setStarted(true);
    setLoading(true);
    const opening = await callClaude([
      { role: "user", content: "Begin the interview. Start with Stage 1 exactly as instructed." }
    ]);
    setMessages([{ role: "assistant", content: opening }]);
    setCurrentStage(detectStage(opening));
    setLoading(false);
  }

  async function sendMessage() {
    if (!input.trim() || loading) return;
    const userMsg = { role: "user", content: input.trim() };
    const newMessages = [...messages, userMsg];
    setMessages(newMessages);
    setInput("");
    setLoading(true);

    const history = newMessages.map(m => ({ role: m.role, content: m.content }));
    const reply = await callClaude(history);
    const assistantMsg = { role: "assistant", content: reply };
    setMessages([...newMessages, assistantMsg]);
    setCurrentStage(s => Math.max(s, detectStage(reply)));
    setLoading(false);
  }

  function handleKey(e) {
    if (e.key === "Enter" && !e.shiftKey) {
      e.preventDefault();
      sendMessage();
    }
  }

  function autoResize() {
    const ta = textareaRef.current;
    if (ta) {
      ta.style.height = "auto";
      ta.style.height = Math.min(ta.scrollHeight, 160) + "px";
    }
  }

  return (
    <div style={{
      minHeight: "100vh",
      background: "#0a0a0f",
      color: "#e8e4d8",
      fontFamily: "'Georgia', 'Times New Roman', serif",
      display: "flex",
      flexDirection: "column",
    }}>
      {/* Grain overlay */}
      <div style={{
        position: "fixed", inset: 0, pointerEvents: "none", zIndex: 0,
        backgroundImage: `url("data:image/svg+xml,%3Csvg viewBox='0 0 256 256' xmlns='http://www.w3.org/2000/svg'%3E%3Cfilter id='noise'%3E%3CfeTurbulence type='fractalNoise' baseFrequency='0.9' numOctaves='4' stitchTiles='stitch'/%3E%3C/filter%3E%3Crect width='100%25' height='100%25' filter='url(%23noise)' opacity='0.04'/%3E%3C/svg%3E")`,
        opacity: 0.4,
      }} />

      {/* Header */}
      <header style={{
        position: "sticky", top: 0, zIndex: 10,
        borderBottom: "1px solid rgba(200,170,100,0.15)",
        background: "rgba(10,10,15,0.95)",
        backdropFilter: "blur(12px)",
        padding: "18px 28px",
        display: "flex", alignItems: "center", justifyContent: "space-between",
      }}>
        <div>
          <div style={{ fontSize: 11, letterSpacing: "0.25em", color: "#c8aa64", textTransform: "uppercase", marginBottom: 4 }}>
            High-Ticket Offer Architect
          </div>
          <div style={{ fontSize: 20, fontWeight: 700, letterSpacing: "-0.01em", color: "#f0ead8" }}>
            Discover Your $3K–$10K Offer
          </div>
        </div>

        {/* Stage tracker */}
        <div style={{ display: "flex", gap: 6, alignItems: "center" }}>
          {STAGES.map(s => (
            <div key={s.id} style={{
              display: "flex", flexDirection: "column", alignItems: "center", gap: 3,
              opacity: currentStage >= s.id ? 1 : 0.3,
              transition: "opacity 0.4s",
            }}>
              <div style={{
                width: 30, height: 30, borderRadius: "50%",
                border: `1.5px solid ${currentStage >= s.id ? "#c8aa64" : "rgba(200,170,100,0.3)"}`,
                background: currentStage === s.id ? "rgba(200,170,100,0.15)" : "transparent",
                display: "flex", alignItems: "center", justifyContent: "center",
                fontSize: 12, color: "#c8aa64",
                transition: "all 0.4s",
              }}>
                {s.icon}
              </div>
              <span style={{ fontSize: 8, color: "#c8aa64", letterSpacing: "0.1em", textTransform: "uppercase" }}>
                {s.label}
              </span>
            </div>
          ))}
        </div>
      </header>

      {/* Chat area */}
      <main style={{
        flex: 1, overflowY: "auto", padding: "32px 20px",
        maxWidth: 780, width: "100%", margin: "0 auto",
        display: "flex", flexDirection: "column", gap: 0,
        position: "relative", zIndex: 1,
      }}>
        {!started ? (
          <div style={{
            display: "flex", flexDirection: "column", alignItems: "center",
            justifyContent: "center", minHeight: "60vh", textAlign: "center", gap: 32,
          }}>
            <div>
              <div style={{
                fontSize: 56, fontWeight: 700, letterSpacing: "-0.03em",
                color: "#f0ead8", lineHeight: 1.1, marginBottom: 16,
              }}>
                Your Experience<br />
                <span style={{ color: "#c8aa64" }}>Is Your Fortune.</span>
              </div>
              <div style={{ fontSize: 17, color: "#a09a8a", lineHeight: 1.6, maxWidth: 480, margin: "0 auto" }}>
                A 6-stage AI interview that transforms your life story into a premium digital offer worth $3,000–$10,000.
              </div>
            </div>

            <div style={{ display: "flex", flexDirection: "column", gap: 12, width: "100%", maxWidth: 380 }}>
              {STAGES.map((s, i) => (
                <div key={s.id} style={{
                  display: "flex", alignItems: "center", gap: 14,
                  padding: "10px 16px",
                  border: "1px solid rgba(200,170,100,0.12)",
                  borderRadius: 8,
                  background: "rgba(200,170,100,0.03)",
                  animation: `fadeSlide 0.4s ${i * 0.07}s both`,
                }}>
                  <span style={{ color: "#c8aa64", fontSize: 16 }}>{s.icon}</span>
                  <span style={{ fontSize: 13, color: "#c8aa648", letterSpacing: "0.05em" }}>
                    <span style={{ color: "#c8aa64", fontWeight: 600 }}>Stage {s.id}</span>
                    <span style={{ color: "#7a7468" }}> — </span>
                    <span style={{ color: "#a09a8a" }}>{s.label}</span>
                  </span>
                </div>
              ))}
            </div>

            <button
              onClick={startInterview}
              style={{
                padding: "16px 48px",
                background: "linear-gradient(135deg, #c8aa64, #a88940)",
                color: "#0a0a0f",
                border: "none",
                borderRadius: 4,
                fontSize: 15,
                fontWeight: 700,
                letterSpacing: "0.12em",
                textTransform: "uppercase",
                cursor: "pointer",
                fontFamily: "inherit",
                transition: "transform 0.2s, box-shadow 0.2s",
              }}
              onMouseEnter={e => { e.target.style.transform = "translateY(-2px)"; e.target.style.boxShadow = "0 8px 32px rgba(200,170,100,0.3)"; }}
              onMouseLeave={e => { e.target.style.transform = "none"; e.target.style.boxShadow = "none"; }}
            >
              Begin Your Interview
            </button>
          </div>
        ) : (
          <>
            {messages.map((m, i) => (
              <MessageBubble key={i} msg={m} />
            ))}
            {loading && <TypingIndicator />}
            <div ref={bottomRef} />
          </>
        )}
      </main>

      {/* Input */}
      {started && (
        <div style={{
          position: "sticky", bottom: 0, zIndex: 10,
          borderTop: "1px solid rgba(200,170,100,0.12)",
          background: "rgba(10,10,15,0.97)",
          backdropFilter: "blur(12px)",
          padding: "16px 20px",
        }}>
          <div style={{ maxWidth: 780, margin: "0 auto", display: "flex", gap: 12, alignItems: "flex-end" }}>
            <textarea
              ref={textareaRef}
              value={input}
              onChange={e => { setInput(e.target.value); autoResize(); }}
              onKeyDown={handleKey}
              placeholder="Share your answer… (Enter to send, Shift+Enter for new line)"
              disabled={loading}
              rows={1}
              style={{
                flex: 1,
                background: "rgba(255,255,255,0.04)",
                border: "1px solid rgba(200,170,100,0.2)",
                borderRadius: 8,
                padding: "12px 16px",
                color: "#e8e4d8",
                fontSize: 15,
                fontFamily: "inherit",
                resize: "none",
                outline: "none",
                lineHeight: 1.6,
                minHeight: 48,
                transition: "border-color 0.2s",
              }}
              onFocus={e => e.target.style.borderColor = "rgba(200,170,100,0.5)"}
              onBlur={e => e.target.style.borderColor = "rgba(200,170,100,0.2)"}
            />
            <button
              onClick={sendMessage}
              disabled={loading || !input.trim()}
              style={{
                width: 48, height: 48,
                background: input.trim() && !loading ? "linear-gradient(135deg, #c8aa64, #a88940)" : "rgba(200,170,100,0.15)",
                border: "none", borderRadius: 8,
                cursor: input.trim() && !loading ? "pointer" : "default",
                display: "flex", alignItems: "center", justifyContent: "center",
                fontSize: 18, color: input.trim() && !loading ? "#0a0a0f" : "#c8aa6460",
                transition: "all 0.2s", flexShrink: 0,
              }}
            >
              ↑
            </button>
          </div>
        </div>
      )}

      <style>{`
        @keyframes fadeSlide {
          from { opacity: 0; transform: translateY(12px); }
          to { opacity: 1; transform: translateY(0); }
        }
        @keyframes pulse {
          0%, 100% { opacity: 0.4; transform: scale(0.8); }
          50% { opacity: 1; transform: scale(1); }
        }
        * { box-sizing: border-box; }
        ::-webkit-scrollbar { width: 6px; }
        ::-webkit-scrollbar-track { background: transparent; }
        ::-webkit-scrollbar-thumb { background: rgba(200,170,100,0.2); border-radius: 3px; }
      `}</style>
    </div>
  );
}

function MessageBubble({ msg }) {
  const isUser = msg.role === "user";
  return (
    <div style={{
      display: "flex",
      justifyContent: isUser ? "flex-end" : "flex-start",
      marginBottom: 20,
      animation: "fadeSlide 0.3s both",
    }}>
      {!isUser && (
        <div style={{
          width: 32, height: 32, borderRadius: "50%",
          background: "linear-gradient(135deg, #c8aa64, #a88940)",
          display: "flex", alignItems: "center", justifyContent: "center",
          fontSize: 14, color: "#0a0a0f", fontWeight: 700,
          flexShrink: 0, marginRight: 12, marginTop: 2,
        }}>A</div>
      )}
      <div style={{
        maxWidth: "78%",
        background: isUser
          ? "linear-gradient(135deg, rgba(200,170,100,0.15), rgba(168,137,64,0.1))"
          : "rgba(255,255,255,0.04)",
        border: `1px solid ${isUser ? "rgba(200,170,100,0.25)" : "rgba(255,255,255,0.07)"}`,
        borderRadius: isUser ? "16px 16px 4px 16px" : "16px 16px 16px 4px",
        padding: "14px 18px",
      }}>
        <div style={{
          fontSize: 15, lineHeight: 1.75,
          color: isUser ? "#e8e4d8" : "#d4cfc4",
          whiteSpace: "pre-wrap",
        }}>
          {msg.content}
        </div>
      </div>
    </div>
  );
}

function TypingIndicator() {
  return (
    <div style={{ display: "flex", alignItems: "center", gap: 12, marginBottom: 20 }}>
      <div style={{
        width: 32, height: 32, borderRadius: "50%",
        background: "linear-gradient(135deg, #c8aa64, #a88940)",
        display: "flex", alignItems: "center", justifyContent: "center",
        fontSize: 14, color: "#0a0a0f", fontWeight: 700,
      }}>A</div>
      <div style={{
        background: "rgba(255,255,255,0.04)",
        border: "1px solid rgba(255,255,255,0.07)",
        borderRadius: "16px 16px 16px 4px",
        padding: "14px 20px",
        display: "flex", gap: 6, alignItems: "center",
      }}>
        {[0, 1, 2].map(i => (
          <div key={i} style={{
            width: 7, height: 7, borderRadius: "50%",
            background: "#c8aa64",
            animation: `pulse 1.2s ${i * 0.2}s ease-in-out infinite`,
          }} />
        ))}
      </div>
    </div>
  );
}
