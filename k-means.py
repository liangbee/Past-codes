# Author: Biyao Liang @ Boston University
# This code is an implementation of K-means clustering with regards to Lloyd's algorithm and an article written by datasicence.
# Python version : 3.6.1
# Make sure you run it in the same/more advanced version of python.
# either reads in a file or just generate data points on its own.
# by default generates data points. 
# the first argument is the name of the input file.
import numpy as np
from random import random
from scipy.spatial import distance
import scipy.io as sio
# 1st step: generate data points as np arrays
# reads in a text file that reads in 

def find_centroid(points,cluster):
     p_list = []
     for i in points:
         a = i.coordinate
         p_list.append(a)
     b = np.mean(np.array(p_list),axis = 0)
     centroid = point(b,cluster,0) 
     return centroid

class point:
    def __init__(self,coordinate, cluster,ID):
        self.coordinate = np.array(coordinate)
        self.cluster = cluster
        self.ID = ID
    def __eq__(self, other):
        a = self.coordinate.tolist()
        b = other.coordinate.tolist()
        c = bool(a == b)
        d = bool (self. cluster == other.cluster)
        return bool(c*d)

def find_distance(a,b):
    c = a.coordinate
    d = b.coordinate
    dst = distance.euclidean(c,d)
    return dst
def new_centroid(points,c_num):
    center = []
    for i in range (1,c_num+1):
        p_list = [] # creating a list for calculating centorids
        for j in points:
            if j.cluster == i:
                p_list.append(j)
            else:
                pass
        a = find_centroid(p_list,i)# find the centoid of this list consisting of all the points that belong to this cluster
        center.append(a)
    return center
                
def regenerate_clusters(points,center):
    p_list = [] # output container
    for i in points:
        dis = [] # distance container
        for j in center:
            a = find_distance(i,j) # find distance between this point and all centers
            dis.append(a) 
            # up til here dis has all distances stored 
        b = np.argmin(dis)+1 # iterate through this list, find shortest distance 
        p = point(i.coordinate,b,i.ID) # create the new point, with same coordinate and different cluster attribute 
        p_list.append(p) # append the new point to p_list.
        # and repeat this process for all i in points.
    for k,l in enumerate(p_list):
        if p_list[k] == points[k]:
            pass
        else:
            for p in p_list:
                printf(p)
            return p_list # the new_sets of points, re-assigned to new 
            break
        return p_list
   
def main_loop(points,center,c_num):
        temp_points = []
        temp_center = []
        while points != temp_points and center != temp_center:
           print("main_looping")
           temp_points = points
           temp_center = center
           points = regenerate_clusters(temp_points,temp_center)
           center = new_centroid(points,c_num)
        print ("main_looped")
        output(points,center)
        analytics(points)
        print ("outputed")
        return points,center

def printf(point):
    print (point.coordinate, point.cluster, point.ID)

def output(points,center):
    point_array = []
    label_array = []
    center_array = []
    ID_array = []
    for i in points:
        point_array.append(i.coordinate)
        a = np.array(point_array)
        label_array.append(i.cluster)
        b = np.array(label_array)
        ID_array.append(i.ID)
        c = np.array(ID_array)
    for j in center:
        center_array.append(j.coordinate)
        d = np.array(center_array)
    sio.savemat('k-meansDatapoints.mat',{'outputpoints':a})
    sio.savemat('k-meansLabels.mat',{'outputlabels':b}) 
    sio.savemat('k-meansID.mat',{'ID':c})
    sio.savemat('k-meansCentroids.mat',{'outputcentoids':d})


def main(cluster_number):
    dp = sio.loadmat('binary_trace_sequence.mat')
    center = sio.loadmat('center.mat')
    center = list(center['center'])
    print("main running")
    centroid = []
    a = list(dp["binary_trace422"])
    points = []
    j = 1
    k = 0
    for i in a:
        b = point(i,1,j)
        j += 1
        points.append(b)  
    for item in points:
        for item2 in center:
            if np.array_equal(item.coordinate,item2):
                centroid.append(item)
            else: 
                pass
    c = regenerate_clusters(points,centroid)
    main_loop(c,centroid,cluster_number)
    return 0

def fileoutput(a,b,dis):
    out = open("output_within.txt","a")
    out.write("coordinate a ", a, "coordinate b ", b, " distance " , dis)
    out.close()
    return 0

def fileoutputb(a,b,dis):
    out = open("output_between.txt","a")
    out.write("coordinate a ", a, "coordinate b ", b, " distance " , dis)
    out.close()
    return 0

def graph(count):
    plt.plot(count)
    plt.ylabel('differences between points')
    plt.show()

def within_cluster_distance(cluster):
    temp = cluster
    count = []
    for point in cluster:
        for point2 in temp:
            dis = find_distance(point,point2)
            fileoutput(point,point2,dis)
            count.append(dis)
        temp.remove(temp[0])
    for item in count:
        if item == 0:
            count.remove(item)
        else:
            pass
    return count

def between_cluster_distance(clustera, clusterb):
    count = []
    for point in clustera:
        for point2 in clusterb:
            dis = find_distance(point,point2)
            fileoutputb(point,point2,dis)
            count.append(dis)
    return count

def analytics(points,cluster_check):
    temp = []
    for i in points:
        if i.cluster == cluster_check:
            temp.append(i)
        else:
            pass
    count = within_cluster_distance(temp)
    graph(count)
    return "within_cluster distance checked"

def analytics(points,cluster_check1,cluster_check2):
    temp = []
    temp2 = []
    for i in points:
        if i.cluster == cluster_check1:
            temp.append(i)
        else if i.cluster == cluster_check2:
            temp2.append(i)
        else:
            pass
    count = between_cluster_distance(temp,temp2)
    graph(count)
    return "between_cluster distance checked"

main(10)

