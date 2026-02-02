a = [
  "Inst Topper",
  "Ryu",
  "SAKE",
  "Flaming Tomatoes",
  "Team A",
  "TEAM TKB",
  "Ambush",
  "Man O War",
  "NextTime",
  "Team Deadline",
  "ONYX",
  "Infinite loopers",
  "Demeter",
  "Vinco",
  "Tantransh",
  "COSMIC CODEX",
  "Dark Knight",
  "Datatype",
  "SVS",
  "NotCoders",
  "not found",
  "Quantum Fang",
  "BitBlasters",
  "Ghouls",
  "3Bots",
  "rookie trio 314",
  "Speed Thinkers",
  "Hunters",
  "Quantum Coders",
  "Neo Stars",
  "The Optimizers",
  "Bugs",
  "Skill Issues",
  "TriExodus",
  "Rise",
  "Xenocoders",
  "TheGamblers"
]

b = [
    "Datatype",
    "Infinite loopers",
    "COSMIC CODEX",
    "3Bots",
    "TEAM GRAVITY",
    "NotCoders",
    "The P2P",
    "Stack Overflowed",
    "Skill Issues",
    "VORTEX",
    "Syntax_error",
    "not_found",
    "Team debugger",
    "Vinco",
    "Speed Thinkers ",
    "Obsidian Ops",
    "CodeBlooded",
    "Man-O-War",
    "Tantransh",
    "SVS",
    "SAKE",
    "Hunters",
    "Ryu",
    "Flaming Tomatoes",
    "NextTime",
    "Team Deadline",
    "Demeter",
    "Team A",
    "TEAM-TKB",
    "Ambush",
    "Ghouls",
    "Error404s",
    "Zenith",
    "Forgecrypt",
    "Last PiXels",
    "AlgoRythms",
    "suvendu kumar sahoo",
    "Quantum Fang"
]

clean_a = set()
for name in a:
    x = name.lower().replace(" ", "").replace("-", "")
    clean_a.add(x)

clean_b = set()
for name in b:
    x = name.lower().replace(" ", "").replace("-", "")
    clean_b.add(x)

print(clean_a-clean_b)


# print(a-b)

