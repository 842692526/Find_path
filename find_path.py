import numpy
import random
import itertools

def distance (x1,y1,x2,y2):
    #Calculate the distance between points
    dis = numpy.sqrt(pow(abs(x2-x1),2) + pow(abs(y2-y1),2))
    return dis

def main(N, r):
    point = list(itertools.product(range(0,100),range(0,100)))
 #   N = int(input("Enter the value of N: "))
    # total number of points in 2D plane ....
    point = random.sample(point, N)
    for i in range(len(point)):
        print("Displaying the coordinates of each point:" ,((i), point[i][0], point[i][1]))

    countsum = 0
    pathsum = 0
    for case in range(len(point)):
       # src = int(input("Please Input the src number:"))
        #dest = int(input("Please Input the dest number:"))
       # r = int(input("Please Input the radius:"))
        src = random.randrange(0, N)
        dest = random.randrange(0, N)
        nodes = []
        cur = src
        count = 0
        path = 0
        mindist = 200
        while(True):
            x1 = point[cur][0]
            y1 = point[cur][1]
            x = point[dest][0]
            y = point[dest][1]
            minnode = -1
            for i in range(N):
                x2 = point[i][0]
                y2 = point[i][1]
                d1 = distance(x1,y1,x2,y2)
                print("The Value of distance between destination " ,cur, "and current point" ,i, "is => " ,d1 )
                if (d1>r):
                    continue
                d2 = distance(x,y,x2,y2)
                print("The Value of distance between destination " ,dest, "and current point " ,i, "is => " ,d2)
                #checking the distances on both perspective (d1 for source and d2 for destination)...
                if(d1 <=r and d2 < mindist):
                    print("+++++++ We are in the checking if statement +++++")
                    mindist = d2
                    minnode = i
                    #updating the current point id into minnode if d1 < r..
                    print( "The value of minnode is: " ,minnode)

            if (cur == minnode):
                print("Hurrah! we are inside of if statement +++++ ")
                path +=1
                break
            if minnode == -1:
                print("Cannot find")
                break
            count += 1

            nodes.append(minnode)
            # nodes = minnode
            cur = minnode
            # minimized distance will become new source...
            print("The value of cur is: " ,cur)
            if (cur == dest):
                # if we reached our destination point...
                path +=1

                break
        countsum += count
        pathsum += path
        print(src, dest, "count ", count )
        print("(",src, ":", point[src][0], ",", point[src][1], ")")
        for i in range(count):
            print("(" ,nodes[i],":",point[ nodes[i] ][0],"," ,point[ nodes[i] ][1], ")")


    print(N ,"countsum ", countsum, pathsum)
random.seed(1)
for i in range(20, 50, 10):
  main(i, 40)



