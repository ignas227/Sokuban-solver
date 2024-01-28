#define xy pair < int , int >
#define x first
#define y second


#include <bits/stdc++.h>

using namespace std;

vector < xy > orbs;



int number = 0;

unordered_map < string , int > visited;
vector < string > solution;

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
int search (string from){
    number ++;
    ///print_gamestate(from);
    if(number % 100000 == 0){
        cout << number << endl;
    }
    ///cout << number << endl;
    if(visited[from] == true){
        return 0;
    }
    visited[from] = true;
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
        xy to = add(player_pos, a);
        xy to2 = add(to, a);
        if(from[to.x * 9 + to.y] == ' '){
            string to_pos = from;
            to_pos[to.x * 9 + to.y] = 'O';
            to_pos[player_pos.x * 9 + player_pos.y] = ' ';
            int answer = search(to_pos);
            if(answer == 1){
                ///print_gamestate(from);
                solution.push_back(from);
                return 1;
            }
        }
        else if(from[to.x * 9 + to.y] == 'X' && from[to2.x * 9 + to2.y] == ' '){
            string to_pos = from;
            to_pos[to.x * 9 + to.y] = 'O';
            to_pos[player_pos.x * 9 + player_pos.y] = ' ';
            to_pos[to2.x * 9 + to2.y] = 'X'; /// changed from #
            int answer = search(to_pos);
            if(answer == 1){
                ///print_gamestate(from);
                solution.push_back(from);
                return 1;
            }
        }
    }
    int out_of = orbs.size();
    int good_count = 0;
    for(auto a : orbs){
        if(from[a.x * 9 + a.y] == 'X'){
            good_count++;
        }
        if(good_count == out_of){
            cout << "WIN" << endl;
            return 1;
        }
    }
    return 0;
}
int main(){
    int level;
    cout << "What level would you like solved? (1-15)" << endl;
    cin >> level;

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

    search(starting_gamestate);
    ///cout << endl << orbs.size() << endl;

    reverse(solution.begin(), solution.end());

    for(int a = 0; a < solution.size(); a++){
        cout << a << endl;
        print_gamestate(solution[a]);
    }

    return 0;
}
