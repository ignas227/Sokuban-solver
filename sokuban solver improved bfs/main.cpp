#define xy pair < int , int >
#define x first
#define y second


#include <bits/stdc++.h>

using namespace std;

vector < xy > orbs;

queue < pair < string , string > > solve_list;

int number = 0;

unordered_map < string , int > visited;
vector < string > solution;
map < string , string > previous;

string this_gamestate;

bool belongs(string gamestate, xy p){
    bool correct = false;
    for(auto b : orbs){
        ///if(to_pos[to2.x * 9 + to2.y] == b.x * 9 + b.y){
        if((p.x * 9 + p.y) == (b.x * 9 + b.y)){
        correct = true;
        ///cout << "aight bro" << endl;
    }
}
return correct;
}

int print_gamestate (string arr){
    for(int a = 0; a < 9; a++){
        for(int b = 0; b < 9; b++){
            cout << arr[a * 9 + b];
        }
        cout << endl;
    }
}

xy add(xy a, xy b){
    xy temp = {a.x + b.x, a.y + b.y};
    return temp;
}
int list_search (string from, string from2){
    number++;
    //*
    if(number % 1000000 == 0){
            print_gamestate(from);
        cout << number << endl;
    }//*/
    ///cout << number << endl;
    ///print_gamestate(from);

    if(visited[from] == true){
        solve_list.pop();
        return 0;
    }
    visited[from] = true;
    previous[from] = from2;
    xy player_pos;
    for(int a = 0; a < 9; a++){
        for(int b = 0; b < 9; b++){
            if(from[a * 9 + b] == 'O'){
                player_pos = {a, b};
            }
        }
    }
    vector < xy > directions;
    directions.push_back({1, 0});
    directions.push_back({0, 1});
    directions.push_back({-1, 0});
    directions.push_back({0, -1});
    for(auto a : directions){
        bool to_push = true;
        xy to = add(player_pos, a);
        xy to2 = add(to, a);
        if(from[to.x * 9 + to.y] == ' '){ /// no box pushing
            string to_pos = from;
            to_pos[to.x * 9 + to.y] = 'O';
            to_pos[player_pos.x * 9 + player_pos.y] = ' ';
            solve_list.push({to_pos, from});
        }
        else if(from[to.x * 9 + to.y] == 'X' && from[to2.x * 9 + to2.y] == ' '){ /// push a box
            string to_pos = from;
            to_pos[to.x * 9 + to.y] = 'O';
            to_pos[player_pos.x * 9 + player_pos.y] = ' ';
            to_pos[to2.x * 9 + to2.y] = 'X';


            //**
            int how_many = 0; /// how many surrounding squares are walls
            xy dir_sum = {0, 0};
            for(auto b : directions){
                xy dir = add(to2, b);
                if(to_pos[dir.x * 9 + dir.y] == '#'){
                    how_many++;
                    dir_sum = add(dir_sum, b);
                }
            }
            bool correct;
            ///cout << dir_sum.x << " " << dir_sum.y << endl;
            if((how_many >= 2) && (!((dir_sum.x == 0) && (dir_sum.y == 0)))){
                ///cout << dir_sum.x << " " << dir_sum.y << endl;
                if(correct == belongs(to_pos, to2)){
                    ///print_gamestate(to_pos);
                    ///return 0;
                    to_push = false;
                }

            }

                    for(int c = 0; c < 2; c++){
                        ///cout << "c : " << c << endl;
                    for(int d = 0; d < 2; d++){
                        int num = 0;
                        for(int e = 0; e < 2; e++){
                            for(int f = 0; f < 2; f++){
                                int square = to_pos[(to2.x + c + e - 1) * 9 + (to2.y + d + f - 1)];
                                if((square == 'X') || (square == '#')){
                                    num++;
                                    ///cout << "num: " << num << endl;
                                }
                            }
                        }
                        if(num == 4){
                            for(int e = 0; e < 2; e++){
                                for(int f = 0; f < 2; f++){
                                    if(to_pos[(to2.x + c + e - 1) * 9 + (to2.y + d + f - 1)] == 'X'){
                                        if(belongs(to_pos, {(to2.x + c + e - 1), (to2.y + d + f - 1)}) == false){
                                            ///return 0;
                                            to_push = false;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            //*/

            if(to_push == true){
                solve_list.push({to_pos, from});
            }
        }
    }
    int out_of = orbs.size();
    int good_count = 0;
    for(auto a : orbs){
        if(from[a.x * 9 + a.y] == 'X'){
            good_count++;
        }
    }
    if(good_count == out_of){
        cout << "WIN" << endl;
        this_gamestate = from;
        return 1;
    }
    return 0;
}
int main(){
    int level;

    cout << "What level would you like solved? (1-15)" << endl;
    cin >> level;

    ///level = 10;
    ///level = 4;

    ///ofstream fout("output.txt");

    string starting_gamestate = "";

    if(level == 4){
    /** # - wall // O - player // ' ' - air // o - blue orbs // X - a box // x - a box on a blue orb */
    starting_gamestate += "#########";
    starting_gamestate += "##O #####";
    starting_gamestate += "## X  ###";
    starting_gamestate += "### # ###";
    starting_gamestate += "#o# #  ##";
    starting_gamestate += "#oX  # ##";
    starting_gamestate += "#o   X ##";
    starting_gamestate += "#########";
    starting_gamestate += "#########";
    }else if(level == 10){
    starting_gamestate += "#########";
    starting_gamestate += "#ooXoo###";
    starting_gamestate += "#oo#oo###";
    starting_gamestate += "# XXX ###";
    starting_gamestate += "#  X  ###";
    starting_gamestate += "# XXX ###";
    starting_gamestate += "#  #O ###";
    starting_gamestate += "#########";
    starting_gamestate += "#########";
    }else if(level == 11){
    starting_gamestate += "#########";
    starting_gamestate += "## O ####";
    starting_gamestate += "## #X  ##";
    starting_gamestate += "# xo o ##";
    starting_gamestate += "#  XX ###";
    starting_gamestate += "### #o###";
    starting_gamestate += "###   ###";
    starting_gamestate += "#########";
    starting_gamestate += "#########";
    }else if(level == 12){
    starting_gamestate += "#########";
    starting_gamestate += "#    ####";
    starting_gamestate += "# X O####";
    starting_gamestate += "##x  ####";
    starting_gamestate += "# x #####";
    starting_gamestate += "# x #####";
    starting_gamestate += "# x #####";
    starting_gamestate += "# o #####";
    starting_gamestate += "#########";
    }else if(level == 13){
    starting_gamestate += "#########";
    starting_gamestate += "###  ####";
    starting_gamestate += "###X ####";
    starting_gamestate += "#  x O###";
    starting_gamestate += "#  x  ###";
    starting_gamestate += "#  x ####";
    starting_gamestate += "###x ####";
    starting_gamestate += "###o#####";
    starting_gamestate += "#########";
    }else if(level == 15){
    starting_gamestate += "#########";
    starting_gamestate += "##    ###";
    starting_gamestate += "##o##X ##";
    starting_gamestate += "# ooX  ##";
    starting_gamestate += "#  #X  ##";
    starting_gamestate += "#  O ####";
    starting_gamestate += "#########";
    starting_gamestate += "#########";
    starting_gamestate += "#########";
    }else if(level == 14){
    starting_gamestate += "#########";
    starting_gamestate += "#   #####";
    starting_gamestate += "# # #   #";
    starting_gamestate += "# X   X #";
    starting_gamestate += "#oo#X#X##";
    starting_gamestate += "#oOX   ##";
    starting_gamestate += "#oo  ####";
    starting_gamestate += "#########";
    starting_gamestate += "#########";
    }
    for(int a = 0; a < 9; a++){
        for(int b = 0; b < 9; b++){
            if(starting_gamestate[a * 9 + b] == 'o' || starting_gamestate[a * 9 + b] == 'x'){
                orbs.push_back({a, b});
                if(starting_gamestate[a * 9 + b] == 'o'){
                    starting_gamestate[a * 9 + b] = ' ';
                }
                if(starting_gamestate[a * 9 + b] == 'x'){
                    starting_gamestate[a * 9 + b] = 'X';
                }
            }
        }
    }
    solution = vector < string > ();
    solve_list = queue < pair < string , string > > ();

    solve_list.push({starting_gamestate, ""});
    while(!solve_list.empty()){
        int answer = list_search(solve_list.front().x, solve_list.front().y);
        if(answer == 1){
            break;
        }
    }

    while(this_gamestate != ""){
        solution.push_back(this_gamestate);
        this_gamestate = previous[this_gamestate];
    }

    reverse(solution.begin(), solution.end());


    cout << "number: " << number << endl;
    for(int a = 0; a < solution.size(); a++){
        cout << a << endl;
        print_gamestate(solution[a]);
    }
    cout << "number: " << number << endl;

    return 0;
}
