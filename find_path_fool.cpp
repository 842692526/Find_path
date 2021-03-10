#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cmath>

using namespace std;

double distance(int x1, int y1, int x2, int y2){
    double d;
    double x_axis_section = double(pow(x1-x2,2));
    double y_axis_section = double(pow(y1-y2,2));

    d = double(sqrt(x_axis_section + y_axis_section));

    return d;
}


int main(){
    srand(2020);
    int N;/// total number of points in 2D plane ....
    cout << "Enter the value of N: ";
    cin >> N;
    int point[N][2]; /// this array will store the cooridinates of each pint...
    int i,j;
    int nodes[N];

    /// generating the coordinates of each points which are within 1000..
    for(i = 0; i < N; i++){
        for (j = 0; j <=1;j++){
            point[i][j] = rand() % 100;
        }
    }

    /// Displaying points coordinates.
    cout <<"Displaying the coordinates of each point: "<< endl;
    for(i = 0; i < N; i++){
        cout << i <<" => ";
        for (j = 0; j <=1;j++){
            cout << point[i][j] << " ";
        }
        cout << endl;
    }


    while(1){
        int src, dest, r;
        cout <<"Please Input the src number:" <<endl;
        cin >> src;
        cout << "Please Input the dest number:"<<endl;
        cin >> dest;
        cout << "Please Input the radius:"<<endl;
        cin >> r;
        int x1, y1, x2, y2, x, y, i; /// x and y are the coordinates of dest and x1 and y1 are the
                                    /// coordinates of current point (start from the source point)
        int count = 0, min;
        double d1, d2;

        x = point[dest][0];
        y = point[dest][1];
        int cur = src;

        while(1) {
            min = 101;
            x1 = point[cur][0];
            y1 = point[cur][1];

            int minnode = -1;
            for(int i = 0; i < N; i++){
                         x2 = point[i][0]; /// x2 and y2 will store the coordinates of current point (selecting one by one)...
                         y2 = point[i][1];
                         d1 = distance(x1 , y1 , x2 , y2);

                         cout << "The Value of distance between current source " << cur <<" and current point " << i
                             << "is => "<< d1 << endl;
                         if (d1 > r)
                             continue;
                         d2 = distance (x , y , x2 , y2);

                         cout << "The Value of distance between destination " << dest <<" and current point " << i
                             << "is => "<< d2 << endl;

                         /// checking the distances on both perspective (d1 for source and d2 for destination)...
                         if(d1 <= r && d2 < min){

                             cout << "+++++++ We are in the checking if statement +++++" <<endl;
                             min = d2;
                             minnode = i; /// updating the current point id into minnode if d1 < r..

                             cout << "The value of minnode is: " << minnode << endl;
                         }

                         getchar();
                     }/// End of the for loop...
           
            
          

            if(cur == minnode) {

                cout << "Hurrah! we are inside of if statement +++++ " << endl;
                break;
            }
            nodes[count++] = minnode;
            cur = minnode;

            cout << "The value of cur is: " << cur << endl;
            getchar();

            /// if we reached our destination point...
            if ( cur == dest ){

                break;
            }

        }/// End of inner while loop...

        for(i = 0; i < count; i++){
            cout << "(" << nodes[i] << " : " << point[nodes[i]][0] << "," << point[nodes[i]][1] << ")" <<" ";
          }
            cout << endl;

    }/// outermost while loop...

    return 0;
}/// End of the main function...
