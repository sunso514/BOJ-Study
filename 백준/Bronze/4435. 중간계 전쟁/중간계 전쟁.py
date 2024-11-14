for i in range(1, int(input()) + 1) :
  
    G = list(map(int, input().split()))
    S = list(map(int, input().split()))
    gs = G[0] + G[1] * 2 + (G[2] + G[3]) * 3 + G[4] * 4 + G[5] * 10
    ss = S[0] + (S[1] + S[2] + S[3]) * 2 + S[4] * 3 + S[5] * 5 + S[6] * 10
    if gs > ss : print(f"Battle {i:d}: Good triumphs over Evil")
    elif gs < ss : print(f"Battle {i:d}: Evil eradicates all trace of Good")
    else : print(f"Battle {i:d}: No victor on this battle field")