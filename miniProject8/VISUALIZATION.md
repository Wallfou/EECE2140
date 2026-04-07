This is the prompt I used for the AI html output


```
Generate a single self-contained HTML file that visualizes this directed network routing problem.

Graph: six nodes labeled 0 through 5. Directed edges with bandwidth labels:
0->1 (100), 0->2 (50), 1->2 (30), 1->3 (80), 2->3 (60), 2->4 (40), 3->4 (90), 3->5 (70), 4->5 (120).

- Draw all nodes and directed edges with arrowheads; show the bandwidth number on or near each edge.
- Use a readable layout so edges do not overlap too badly.
- Show DFS exploration: indicate visit order for the successful search (0, then 1, skip 1->2 because 30<50, then 3, then 4, then 5). You can number nodes or use a short legend or side panel describing the order and which edges were skipped and why.
- Visually distinguish the final feasible path 0->1->3->4->5 (e.g. thicker or highlighted edges and nodes on the path) from edges not on that path.
- Use a cohesive color scheme and legible typography; the page should open in a browser as one file with no build step.

Output only the complete HTML source.
```