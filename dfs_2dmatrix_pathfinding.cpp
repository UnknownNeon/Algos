/*
* NOTE : THIS CODE IS AWFULLY SIMILAR TO BFS ,,,,, THE ONLY DIFFERENCE BEING IT USES THE STACK DATA STRUCTURE
* A program to Explore the DFS path-finding algo
* Used my previous stack impl to maintain the stack state
*
*/

#include <iostream>
#include <vector>
#include <stack.hpp>

enum PATH {
    EMPTY = -1,
    STARTING_NODE,
    TOP,
    RIGHT,
    LEFT,
    DOWN,
    UP
};

int main(){

    
    // 1 is Denoting the start and 2 denotes the end .... 

    const int M = 5;
    const int N = 5;

    int map[M][N] = {   {1,0,0,0,2},
                        {0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0} };

                        
    //to keep track of the visited node we initialize another 2d array
    int visited_map[M][N] = {};
    int path_tracer[M][N] = {};
    
    stack<int> s_row(999);
    stack<int> s_col(999);

    //Initializing a directional matrix
    int dr[4] = { 0 , 1 , -1 , 0 }; //  R D U L
    int dc[4] = { 1 , 0  , 0 , -1};

     //Initializing the first Starting row in queue Here it is 0,0 
    int sr , sc ;
    sr = 0; 
    sc = 0;
    s_col.push(sc);
    s_row.push(sr);

    //We also store the starting node in our path matrix
    path_tracer[sr][sc] = PATH::STARTING_NODE;

    //Starting the loop of bfs 

    while(s_row.size() != 0){

        //Exploring current node 
        sr = s_row.pop();
        sc = s_col.pop();

        if(map[sr][sc] == 2)
        {
            std::cout << "Found Node at: " << sr <<":::"<< sc <<std::endl;
            break;
        }


        visited_map[sr][sc] = -1;

        int tr , tc;
        //PUshing Neighbours to explore on the stack
        for(int i = 0 ; i < 4 ; i++){
            
            tr = sr + dr[i];
            tc = sc + dc[i];


            if(tc >= N || tr >= M){ continue; }
            if(tr < 0 || tc < 0){ continue; }
            if(visited_map[tr][tc] == -1){continue;}

            //The path trcer with auxilary array

            if(i == 0){
                path_tracer[tr][tc] = PATH::LEFT;
            }
            else if(i == 1){
                path_tracer[tr][tc] = PATH::UP;
            }
            else if(i == 2){
                path_tracer[tr][tc] = PATH::DOWN;
            }
            else if(i == 3){
                path_tracer[tr][tc] = PATH::RIGHT;
            }

            s_row.push(tr);
            s_col.push(tc);
            
        }

    }



    //Now SR and SC are our Node positoins whoch we searched 
    //From final node we traverse to our starting node giving us our path
    
    std::cout << "Running the path finding algo to trace the path from final node "<< std::endl;
    while(true){
        if(path_tracer[sr][sc] == PATH::STARTING_NODE){
            std::cout << "STARTING NODE REACHED" << std::endl;
            break;
        }
        if(path_tracer[sr][sc] == PATH::LEFT){
            sr = sr ;
            sc = sc - 1;
            std::cout << "LEFT" << "\t";
        }
        if(path_tracer[sr][sc] == PATH::RIGHT){
            sr = sr ;
            sc = sc + 1;
             std::cout << "RIGHT" << "\t";
        }
        if(path_tracer[sr][sc] == PATH::DOWN){
            sr = sr + 1;
            sc = sc;
             std::cout << "DOWN" << "\t";
        }
        if(path_tracer[sr][sc] == PATH::UP){
            sr = sr - 1;
            sc = sc;
             std::cout << "UP" << "\t";
        }

    }
    return 0;
}
