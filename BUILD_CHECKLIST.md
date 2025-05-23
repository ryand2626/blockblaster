# Brick Blaster iOS — Viral Growth Build Checklist v2.0

## 🚀 North-Star Metrics
- [ ] D1 retention ≥ 50%
- [ ] D7 retention ≥ 25%
- [ ] Organic K-factor ≥ 0.4 (Avg Invites / DAU × Invite CVR)
- [ ] Shares per DAU ≥ 0.6
- [ ] ARPDAU ≥ $0.15 without pay-wall drop‐off
- [ ] 5-star rating ratio ≥ 80%

## 🧩 Core Tech Stack
### Project Setup
- [ ] Xcode (SwiftUI + SpriteKit) or Unity 2022 LTS — pick one & lock
- [x] Shared C++ deterministic-physics library
- [ ] Feature-flag framework for instant A/B roll-outs
- [ ] CI/CD: GitHub Actions → TestFlight → App Store Connect
- [ ] Firebase Remote Config + Crashlytics
- [ ] Analytics event schema (Amplitude + Firebase)

### Performance & Quality
- [ ] 60 FPS on iPhone XR+
- [ ] Cold start < 2.5 s, zero-stall loading
- [ ] RAM ≤ 350 MB on iPhone 8
- [ ] Battery drain < 4% per 10 min stress test
- [ ] Audio latency < 25 ms (music-sync mode)

## 🎮 Gameplay Pillars
### Core Loop
- [x] One-thumb drag-anywhere paddle
- [ ] Frame-perfect ball physics & predictive ricochet line
- [ ] "Smash Combo" multiplier → escalating VFX/SFX + haptics
- [ ] Camera kicks & screen shake for juice

### Music-Sync Mode
- [ ] Local-file & Spotify analyser (FFT)
- [ ] Auto-chart bricks to beat/downbeat
- [ ] Adaptive soundtrack — add layers per combo tier
- [ ] Beat-drop slo-mo & glow (auto-records share clip)

### Progression & Meta
- [ ] Roguelite 10-wave runs (+ boss) with shareable seed code
- [ ] Draft 2-of-5 random power-ups every 3 waves
- [ ] Meta upgrade tree (damage, dash, cosmetics)
- [ ] Daily & weekly quests with streak chest
- [ ] Season track (free + premium)

### Competitive & Social
- [ ] Async PvP ghost battles & tap-to-rematch friend ghost
- [ ] Daily seeded leaderboard auto-records 15s vertical clip
- [ ] SharePlay live duels (visionOS ready)
- [ ] Clans (5-20 players) unlocking co-op brick raids

## 📱 UX / UI
- [ ] Thumb-zone HUD (everything reachable one-handed)
- [ ] Dynamic font scaling & colour-blind palettes
- [ ] 3-step interactive tutorial (skippable)
- [ ] Contextual tool-tips on struggle events
- [ ] Zero-friction ad & IAP surfaces (never mid-fail)

## 💸 Monetisation (Player-First)
### IAP
- [ ] Battle Pass with soft/hard-currency lanes
- [ ] Gem bundles (first-time ×2)
- [ ] Cosmetic shop (skins, trails, brick themes)
- [ ] Limited-time offers aligned with Live Ops calendar

### Ads
- [ ] Rewarded — Revive, Daily Double, Open Chest Early
- [ ] Interstitial cap ≤ 2 per session
- [ ] Ad-free one-time bundle $4.99

## 🌱 Viral Growth Loops
- [ ] Instant "Share Clip" button after epic moment (auto-gif < 15s)
- [ ] TikTok-ready export (vertical, captions, music)
- [ ] Invite link deep-links to same seed + friend ghost
- [ ] Beat Builder UGC level editor unlocked at Level 5
- [ ] Creator code + revenue share for influencers
- [ ] Referral quest: both players earn cosmetic after first match
- [ ] Opt-in push: "Friend just beat your score — rematch?"

## 📈 Experimentation & Data
- [ ] Atomic event taxonomy documented
- [ ] Real-time dashboards (Mixpanel / Looker)
- [ ] Alert if D1 < target within 2h cohort window
- [ ] A/B pipelines for onboarding, share CTAs, ad timing, drop rates

## ⚙️ Testing & QA
- [ ] 90% unit test coverage on core lib
- [ ] Structured playtest script across 5 personas
- [ ] Cloud device farm regression (iPhone 8 → 15)
- [ ] Accessibility pass (VoiceOver, colour-blind)

## 🚀 Launch & Live Ops
### Soft-Launch
- [ ] Tier-4 markets (CA, AU, Nordics) KPI gating
- [ ] 20 cheap-CPI creative tests
- [ ] Retention push copy A/B

### Global Launch
- [ ] Day-0 influencer stream kit & embargo lift
- [ ] App Store featuring pitch deck
- [ ] Public 30-day content roadmap

### Live Ops
- [ ] Weekly brick pattern packs
- [ ] Monthly crossover IP events
- [ ] Live tournament weekends (bracket share)
- [ ] Community polls choose next power-up

## 🔒 Privacy & Compliance
- [ ] ATT pre-prompt → Apple ATT dialog
- [ ] GDPR, COPPA, CCPA audits
- [ ] Secure backend + anti-tamper checksums
- [ ] Fair-matchmaking anti-smurf
- [ ] Remote-config global kill-switch
