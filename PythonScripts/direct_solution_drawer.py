import matplotlib.pyplot as plt
import numpy as np
import os

DATA_PATH = "Data\\Output\\DirectAnswer.txt" # to debug: ..\\Data\\Output\\DirectAnswer.txt
IMAGE_PATH = "Data\\Pictures\\" # to debug: ..\\Data\\Pictures\\

class Point:
    def __init__(self, _x : float, _y : float, _z : float):
        self.x = _x
        self.y = _y
        self.z = _z

class Vector:
    def __init__(self, _dx : float, _dy : float, _dz : float):
        self.dx = _dx
        self.dy = _dy
        self.dz = _dz

class Reader:
    def __init__(self, path):
        self.path_to_read = os.path.abspath(path)
    def read(self):
        data = str()
        with open(self.path_to_read, 'r') as rd:
            data = rd.read()
        return data

class Drawer:
    def __init__(self, path):
        self.path_to_draw = os.path.abspath(path)

    def draw(self, points, b_vectors):
        x = []
        bx = []
        by = []
        bz = []

        for i in range(len(points)):
            x.append(points[i].x)
            bx.append(b_vectors[i].dx)
            by.append(b_vectors[i].dy)
            bz.append(b_vectors[i].dz)

        self.__draw_bx_above_x__(x, bx)
        self.__draw_by_above_x__(x, bx)
        self.__draw_bz_above_x__(x, bz)

    def __draw_bx_above_x__(self, x, b_vectors_x):
        plt.plot(x, b_vectors_x)
        plt.savefig(self.path_to_draw + "\\" + "Bx.png")
        plt.clf()
        

    def __draw_by_above_x__(self, x, b_vectors_y):
        plt.plot(x, b_vectors_y)
        plt.savefig(self.path_to_draw + "\\" + "By.png")
        plt.clf()

    def __draw_bz_above_x__(self, x, b_vectors_z):
        plt.plot(x, b_vectors_z)
        plt.savefig(self.path_to_draw + "\\" + "Bz.png")
        plt.clf()

def main():
    rdr = Reader(DATA_PATH)
    data = rdr.read().split('\n')
    points = []
    b_vector = []
    for row in data:
        if row != '':
            row_arr = row.split(' ')
            points.append(Point(float(row_arr[0]), float(row_arr[1]), float(row_arr[2])))
            b_vector.append(Vector(float(row_arr[3]), float(row_arr[4]), float(row_arr[5])))
    if len(points) != len(b_vector):
        raise Exception("Error during reading. List of points has different size with list of b_vector.")
    
    drawer = Drawer(IMAGE_PATH)
    drawer.draw(points, b_vector)

if __name__ == "__main__":
    main()
