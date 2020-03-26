#include <iostream>

void searchExit(std::string* arr, int col, int rw, bool *f){
    arr[rw][col] = '.';

    if(isalpha(arr[rw][col])){
        std::cout << arr[rw][col] << " ";
        *f = true;
    }
    if(isalpha(arr[rw+1][col])){
        std::cout << arr[rw+1][col] << " ";
        *f = true;
    }
    if(isalpha(arr[rw-1][col])){
        std::cout << arr[rw-1][col] << " ";
        *f = true;
    }
    if(isalpha(arr[rw][col+1])){
        std::cout << arr[rw][col+1] << " ";
        *f = true;
    }
    if(isalpha(arr[rw][col-1])){
        std::cout << arr[rw][col-1] << " ";
        *f = true;
    }

    if(arr[rw+1][col] == ' '){
        searchExit(arr, col, rw+1, f);
    }
    if(arr[rw-1][col] == ' '){
        searchExit(arr, col, rw-1, f );
    }
    if(arr[rw][col+1] == ' '){
        searchExit(arr, col+1, rw, f);
    }
    if(arr[rw][col-1] == ' '){
        searchExit(arr, col-1, rw, f);
    }


}


int main(){
    std::string maze[25] = {
        "####B######################",
        "# #       #   #      #    #",
        "# # # ###### #### ####### #",
        "# # # #       #   #       #",
        "#   # # ######### # ##### #",
        "# # # #   #       #     # #",
        "### ### ### ############# #",
        "# #   #     # #           #",
        "# # #   ####### ###########",
        "# # # #       # #         C",
        "# # ##### ### # # ####### #",
        "# # #     ### # #       # #",
        "#   ##### ### # ######### #",
        "######### ### #           #",
        "# ####### ### #############",
        "A           #   ###   #   #",
        "# ############# ### # # # #",
        "# ###       # # ### # # # #",
        "# ######### # # ### # # # F",
        "#       ### # #     # # # #",
        "# ######### # ##### # # # #",
        "# #######   #       #   # #",
        "# ####### ######### #######",
        "#         #########       #",
        "#######E############D######"
        };

    int column, row;
    std::cin >> column >> row;

    bool f = false;

    if(column > 26 || row > 24 || maze[row][column] == '#'){
        std::cout << "invalid coordinates";
        return 0;
    }

    searchExit(maze, column, row, &f);

    std::cout << std::endl;
    for(int i=0; i < 25; i++){
        std::cout << maze[i] << std::endl;
    }

    if(!f){
        std::cout << "no exit";
    }
}













