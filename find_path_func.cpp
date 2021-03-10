#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cmath>

using namespace std;

int const MAX_POINT = 200; /// Global variable (every body can access this variable)...

double distance(int x1, int y1, int x2, int y2){
    double d;
    double x_axis_section = double(pow(x1-x2,2));
    double y_axis_section = double(pow(y1-y2,2));

    d = double(sqrt(x_axis_section + y_axis_section));

    return d;
}

/// This function will return next point as source...
int FindNextpoint(int point[][2], int N, int cur, int dest, int x, int y, int r, int min){

    int min_dist_node = -1; /// min_dist_node will save the next node id which has the least distance..

    int x1 = point[cur][0];
    int y1 = point[cur][1];

    for(int i = 0; i < N; i++){

        int x2 = point[i][0]; /// x2 and y2 will store the coordinates of current point (selecting one by one)...
        int y2 = point[i][1];
        int d1 = distance(x1 , y1 , x2 , y2);

        cout << "The Value of distance between current source " << cur <<" and current point " << i
            << " is => "<< d1 << endl;
                //if (d1 > r){
                   // continue;
               // }
        int d2 = distance (x , y , x2 , y2);

        cout << "The Value of distance between destination " << dest <<" and current point " << i
            << " is => "<< d2 << endl;

        /// checking the distances on both perspective (d1 for source and d2 for destination)...
        if(d1 <= r && d2 < min){

            cout << "+++++++ We are in the checking if statement +++++" <<endl;
            min = d2;
            min_dist_node = i; /// updating the current point id into min_dist_node if d1 < r..

            cout << "The value of minnode is: " << min_dist_node << endl;
        }

        getchar();
    }/// End of the for loop...

    return min_dist_node;

}/// End of the Function...


/// This function will print out the coordinates of points stored in 'points' array...
void Displaying_points_coord(int points[MAX_POINT][2], int N){

    for (int i = 0; i < N; i++){
        cout << i <<" => ";
        for (int j = 0; j <=1;j++){

            cout << points[i][j] << " ";

        }
        cout << endl;
    }

}/// End of the Function..

/// This function will generate and store x and y coordinates in array point...
void generate_points_coord(int points[MAX_POINT][2], int N){

    /// generating the coordinates of each points which are within 100..
    for(int i = 0; i < N; i++){
        for (int j = 0; j <=1;j++){
            points[i][j] = rand() % 100;
        }
    }

}/// End of the Function...

int main(){
    srand(2020);
    int N;/// total number of points in 2D plane ....
    cout << "Enter the value of N: ";
    cin >> N;
    int points[N][2]; /// this array will store the cooridinates of each pint...
    int nodes[N]; /// this array will save the least distanced node towards the destination...

    /// generating the coordinates of each points which are within 1000..
    generate_points_coord(points, N); /// total number of points are N..

    /// Displaying points coordinates.
    cout <<"Displaying the coordinates of each point: "<< endl;
    Displaying_points_coord(points, N);

    while(1){
        int src, dest, r;
        cout <<"Please Input the src number:" <<endl;
        cin >> src;
        cout << "Please Input the dest number:"<<endl;
        cin >> dest;
        cout << "Please Input the radius:"<<endl;
        cin >> r;
        int count = 0, min;

        int x = points[dest][0];
        int y = points[dest][1];
        int cur = src;

        while(1) {
            min = 101;
            /// This function will return the least distanced point as next point (source)...
            int minnode = FindNextpoint(points, N, cur, dest, x, y, r, min);

            cout << "Next Current node, which has the least distance from itself to the Source point"
                << minnode << endl;

            if(cur == minnode) {

                cout << "Hurrah! we are inside of if statement +++++ " << endl;
                break;
            }
            nodes[count++] = minnode;
            cur = minnode; /// minimized distance will become new source...

            cout << "The value of cur is: " << cur << endl;
            getchar();

            /// if we reached our destination point...
            if ( cur == dest ){

                break;
            }

        }/// End of inner while loop...

        for(int i = 0; i < count; i++){
            cout << "(" << nodes[i] << " : " << points[nodes[i]][0] << "," << points[nodes[i]][1] << ")" <<" ";
          }
            cout << endl;

    }/// outermost while loop...

    return 0;
}/// End of the main function...
