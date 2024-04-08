# quoridor
This is a C++ implementation of different agents to play Quoridor.

## Game Notation
We represent the Board in the following way:
```
    A  B  C  D  E  F  G  H   
 ┌──────────────────────────┐
 │            bb            │
8│  +  +  +  +  +  +  +  +  │
 │                          │
7│  +  +  +  +  +  +  +  +  │
 │                          │
6│  +  +  +  +  +  +  +  +  │
 │                          │
5│  +  +  +  +  +  +  +  +  │
 │                          │
4│  +  +  +  +  +  +  +  +  │
 │                          │
3│  +  +  +  +  +  +  +  +  │
 │                          │
2│  +  +  +  +  +  +  +  +  │
 │                          │
1│  +  +  +  +  +  +  +  +  │
 │            aa            │
 └──────────────────────────┘
```

Moves can be noted as player moves, which can be [U]p, [R]ight, [D]own, [L]eft.
Positioning a barrier works by the position of the center of the barrier followed by [H]orizontal or [V]ertical.
Player a starts at the bottom and player b at the top. Player a starts.

E.g., after UDA8HG5V, the board would look like this:
```
    A  B  C  D  E  F  G  H   
 ┌──────────────────────────┐
 │                          │
8│──+──+  +  +  +  +  +  +  │
 │            bb            │
7│  +  +  +  +  +  +  +  +  │
 │                          │
6│  +  +  +  +  +  +  +  +  │
 │                    │     │
5│  +  +  +  +  +  +  +  +  │
 │                    │     │
4│  +  +  +  +  +  +  +  +  │
 │                          │
3│  +  +  +  +  +  +  +  +  │
 │                          │
2│  +  +  +  +  +  +  +  +  │
 │            aa            │
1│  +  +  +  +  +  +  +  +  │
 │                          │
 └──────────────────────────┘
```
