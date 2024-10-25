dct = { "Algorithm": "204", "DataAnalysis": "207", "ArtificialIntelligence": "302", "CyberSecurity": "B101", "Network": "303", "Startup": "501", "TestStrategy": "105" }
N = int(input())
s = [input() for i in range(N)]
for i in s:
  print(dct[i])