class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.graph = [[0 for a in range(vertices)] for a in range(vertices)]

    def is_safe(self, v, color, c):
        for i in range(self.vertices):
            if self.graph[v][i] == 1 and color[i] == c:
                return False
        return True
    
    def graph_coloring_util(self, m, color, v):
        if v == self.vertices:
            return True
        for c in range(1, m + 1):
            if self.is_safe(v, color, c):
                color[v] = c
                if self.graph_coloring_util(m, color, v + 1):
                    return True
                color[v] = 0

    def graph_coloring(self, m):
        color = [0] * self.vertices
        if not self.graph_coloring_util(m, color, 0):
            return False
        print("Solution exists: Following are the assigned colors:")
        for c in color:
            print(c, end=" ")
        return True
        

# Example usage:
if __name__ == "__main__":
    vertices = int(input("Enter the number of vertices: "))
    g = Graph(vertices)
    print("Enter the adjacency matrix (0 or 1):")
    for i in range(vertices):
        for j in range(vertices):
            g.graph[i][j] = int(input(f"Is vertex {i} adjacent to vertex {j}? (0 or 1): "))
    m = int(input("Enter the number of colors: "))
    if g.graph_coloring(m):
        print("Solution found.")
    else:
        print("Solution does not exist.")

#Sample input 4 0 1 1 0 1 0 1 1 1 1 0 1 0 1 1 0 3 
#4 x 4 matrix = 
# 0 1 1 0
# 1 0 1 1
# 1 1 0 1
# 0 1 1 0
