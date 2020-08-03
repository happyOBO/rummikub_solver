#include <iostream>
#include <vector>
#include <utility> // pair
#include <bitset>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>


#define BLACK 0
#define BLUE 36
#define RED 31
#define YELLOW 33


using namespace std;
void error_msg();

int num_of_red_tiles,num_of_yellow_tiles,num_of_black_tiles,num_of_blue_tiles,num_of_total_tiles = 0;
map<int,int> red_tiles;
map<int,int> blue_tiles;
map<int,int> yellow_tiles;
map<int,int> black_tiles;

int num_of_table_red_tiles,num_of_table_yellow_tiles,num_of_table_black_tiles, num_of_table_blue_tiles,num_of_table_total_tiles =0;
map<int,int> table_red_tiles;
map<int,int> table_blue_tiles;
map<int,int> table_yellow_tiles;
map<int,int> table_black_tiles;


void show_ascii_art(void)
{
    cout<<
    "\n ____                                _  _            _       ____          _                    \n"<<
    "|  _ \\  _   _  _ __ ___   _ __ ___  (_)| | __ _   _ | |__   / ___|   ___  | |__   __  ___  _ __ \n"<<
    "| |_) || | | || '_ ` _ \\ | '_ ` _ \\ | || |/ /| | | || '_ \\  \\___ \\  / _ \\ | |\\ \\ / / / _ \\| '__|\n"<<
    "|  _ < | |_| || | | | | || | | | | || ||   < | |_| || |_) |  ___) || (_) || | \\ V / |  __/| |   \n"<<
    "|_| \\_\\ \\__,_||_| |_| |_||_| |_| |_||_||_|\\_\\ \\__,_||_.__/  |____/  \\___/ |_|  \\_/   \\___||_|   \n"<<
    "                                                                                                \n"<<endl;
    cout<<
    "                         ____ ____ _  _ ____    ____ ___ ____ ____ ___ \n"<<
    "                         | __ |__| |\\/| |___    [__   |  |__| |__/  |  \n"<<
    "                         |__] |  | |  | |___    ___]  |  |  | |  \\  | \n"<<endl;
}

void init(void)
{
    red_tiles.clear();
    yellow_tiles.clear();
    black_tiles.clear();
    blue_tiles.clear();
    table_red_tiles.clear();
    table_blue_tiles.clear();
    table_yellow_tiles.clear();
    table_black_tiles.clear();

    for(int i = 1; i<= 13; i++)
    {
        red_tiles.insert(make_pair(i, 0));
        yellow_tiles.insert(make_pair(i, 0));
        black_tiles.insert(make_pair(i, 0));
        blue_tiles.insert(make_pair(i, 0));
        table_red_tiles.insert(make_pair(i, 0));
        table_yellow_tiles.insert(make_pair(i, 0));
        table_black_tiles.insert(make_pair(i, 0));
        table_blue_tiles.insert(make_pair(i, 0));
    }
    num_of_red_tiles = 0;
    num_of_yellow_tiles = 0;
    num_of_black_tiles = 0;
    num_of_blue_tiles = 0;
    num_of_total_tiles = 0;
    num_of_table_red_tiles = 0;
    num_of_table_yellow_tiles = 0;
    num_of_table_black_tiles = 0;
    num_of_table_blue_tiles = 0;
    num_of_table_total_tiles = 0;
}

void add_tiles(void)
{
    try
    {
        cout<<"Write down the tiles you have.\n"<<endl;
        cout<<"# of Received Red Tiles (ex: 5): ";
        cin>>num_of_red_tiles;
        cout<<"Received Red Tiles (ex: 1 3 5): ";
        for(int i = 0; i< num_of_red_tiles; i++)
        {
            int tile;
            cin>>tile;
            red_tiles[tile]++;
        }

        cout<<"# of Received Blue Tiles (ex: 5): ";
        cin>>num_of_blue_tiles;
        cout<<"Received Blue Tiles (ex: 1 3 5): ";
        for(int i = 0; i< num_of_blue_tiles; i++)
        {
            int tile;
            cin>>tile;
            if(tile > 13) error_msg();
            blue_tiles[tile]++;
        }

        cout<<"# of Received Yellow Tiles (ex: 5): ";
        cin>>num_of_yellow_tiles;
        cout<<"Received Yellow Tiles (ex: 1 3 5): ";
        for(int i = 0; i< num_of_yellow_tiles; i++)
        {
            int tile;
            cin>>tile;
            if(tile > 13) error_msg();
            yellow_tiles[tile]++;
        }
        
        cout<<"# of Received Black Tiles (ex: 5): ";
        cin>>num_of_black_tiles;
        cout<<"Received Black Tiles (ex: 1 3 5): ";
        for(int i = 0; i< num_of_black_tiles; i++)
        {
            int tile;
            cin>>tile;
            if(tile > 13) error_msg();
            black_tiles[tile]++;
        }
        num_of_total_tiles += num_of_red_tiles;
        num_of_total_tiles += num_of_yellow_tiles;
        num_of_total_tiles += num_of_blue_tiles;
        num_of_total_tiles += num_of_black_tiles;
    }
    catch(int err)
    {
        error_msg();
    }
 
}


void add_table_tiles(bool is_user)
{
    try
    {
        cout<<"Write down the new tiles on the table.\n"<<endl;
        cout<<"# of new Red Tiles (ex: 5): ";
        cin>>num_of_table_red_tiles;
        cout<<"new Red Tiles (ex: 1 3 5): ";
        for(int i = 0; i< num_of_table_red_tiles; i++)
        {
            int tile;
            cin>>tile;
            if(is_user)
            {
                if(red_tiles[tile] > 0)
                {
                    red_tiles[tile]--;
                    num_of_total_tiles--;
                }
                else
                {
                    error_msg();
                    return ;
                }
            }
            table_red_tiles[tile]++;
        }

        cout<<"# of new Blue Tiles (ex: 5): ";
        cin>>num_of_table_blue_tiles;
        cout<<"new Blue Tiles (ex: 1 3 5): ";
        for(int i = 0; i< num_of_table_blue_tiles; i++)
        {
            int tile;
            cin>>tile;
            if(is_user)
            {
                if(blue_tiles[tile] > 0)
                {
                    blue_tiles[tile]--;
                    num_of_total_tiles--;
                }
                else
                {
                    error_msg();
                    return ;
                }
            }
            table_blue_tiles[tile]++;
        }

        cout<<"# of new Yellow Tiles (ex: 5): ";
        cin>>num_of_table_yellow_tiles;
        cout<<"new Yellow Tiles (ex: 1 3 5): ";
        for(int i = 0; i< num_of_table_yellow_tiles; i++)
        {
            int tile;
            cin>>tile;
            if(is_user)
            {
                if(yellow_tiles[tile] > 0)
                {
                    yellow_tiles[tile]--;
                    num_of_total_tiles--;
                }
                else
                {
                    error_msg();
                    return ;
                }
            }
            table_yellow_tiles[tile]++;
        }
        
        cout<<"# of new Black Tiles (ex: 5): ";
        cin>>num_of_table_black_tiles;
        cout<<"new Black Tiles (ex: 1 3 5): ";
        for(int i = 0; i< num_of_table_black_tiles; i++)
        {
            int tile;
            cin>>tile;
            if(is_user)
            {
                if(black_tiles[tile] > 0)
                {
                    black_tiles[tile]--;
                    num_of_total_tiles--;
                }
                else
                {
                    error_msg();
                    return ;
                }
            }
            table_black_tiles[tile]++;
        }
        num_of_table_total_tiles += num_of_table_red_tiles;
        num_of_table_total_tiles += num_of_table_yellow_tiles;
        num_of_table_total_tiles += num_of_table_blue_tiles;
        num_of_table_total_tiles += num_of_table_black_tiles;
    }
    catch(int err)
    {
        error_msg();
    }
 
}

void print_table_tiles()
{
    try
    {
        for(int j = 1; j <= num_of_table_total_tiles; j++)
        {
            printf(".___  ");
        }
        cout<<endl;
        for(int i = 1; i<= 13; i++)
        {
            if(table_red_tiles[i] != 0)
            {
                for(int j = 0; j < table_red_tiles[i]; j++)
                {
                    printf("|");
                    printf("\033[%dm%2d\033[0m",RED, i);
                    printf("|  ");
                }

            }
            
        }
        for(int i = 1; i<= 13; i++)
        {
            if(table_blue_tiles[i] != 0)
            {

                for(int j = 0; j < table_blue_tiles[i]; j++)
                {
                    printf("|");
                    printf("\033[%dm%2d\033[0m",BLUE, i);
                    printf("|  ");
                }
            }    
        }
        for(int i = 1; i<= 13; i++)
        {
            if(table_yellow_tiles[i] != 0)
            {
                for(int j = 0; j < table_yellow_tiles[i]; j++)
                {
                    printf("|");
                    printf("\033[%dm%2d\033[0m",YELLOW, i);
                    printf("|  ");
                }
            }
        }
        for(int i = 1; i<= 13; i++)
        {
            if(table_black_tiles[i] != 0)
            {
                for(int j = 0; j < table_black_tiles[i]; j++)
                {
                    printf("|");
                    printf("\033[%dm%2d\033[0m",BLACK, i);
                    printf("|  ");
                }
            }
        } 
        cout<<endl;
        for(int j = 1; j <= num_of_table_total_tiles; j++)
        {
            printf("|__|  ");
        }
        cout<<endl;
    }
    catch(int err)
    {
        error_msg();
    }

}



void print_user_tiles()
{
    try
    {
        for(int j = 1; j <= num_of_total_tiles; j++)
        {
            printf(".___  ");
        }
        cout<<endl;
        for(int i = 1; i<= 13; i++)
        {
            if(red_tiles[i] != 0)
            {
                for(int j = 0; j < red_tiles[i]; j++)
                {
                    printf("|");
                    printf("\033[%dm%2d\033[0m",RED, i);
                    printf("|  ");
                }

            }
            
        }
        for(int i = 1; i<= 13; i++)
        {
            if(blue_tiles[i] != 0)
            {

                for(int j = 0; j < blue_tiles[i]; j++)
                {
                    printf("|");
                    printf("\033[%dm%2d\033[0m",BLUE, i);
                    printf("|  ");
                }
            }    
        }
        for(int i = 1; i<= 13; i++)
        {
            if(yellow_tiles[i] != 0)
            {
                for(int j = 0; j < yellow_tiles[i]; j++)
                {
                    printf("|");
                    printf("\033[%dm%2d\033[0m",YELLOW, i);
                    printf("|  ");
                }
            }
        }
        for(int i = 1; i<= 13; i++)
        {
            if(black_tiles[i] != 0)
            {
                for(int j = 0; j < black_tiles[i]; j++)
                {
                    printf("|");
                    printf("\033[%dm%2d\033[0m",BLACK, i);
                    printf("|  ");
                }
            }
        } 
        cout<<endl;
        for(int j = 1; j <= num_of_total_tiles; j++)
        {
            printf("|__|  ");
        }
        cout<<endl;
    }
    catch(int err)
    {
        error_msg();
    }

}

void error_msg()
{
    cout<<
    "\n_   _ ____ _  _    ___ _   _ ___  ____ ___     _ ___    _ _ _ ____ ____ _  _ ____     ____ ____ ___ ____ _   _  \n"<<
    " \\_/  |  | |  |     |   \\_/  |__] |___ |  \\    |  |     | | | |__/ |  | |\\ | | __     |__/ |___  |  |__/  \\_/   \n"<<
    "  |   |__| |__|     |    |   |    |___ |__/    |  |     |_|_| |  \\ |__| | \\| |__] .   |  \\ |___  |  |  \\   |   .\n"<<endl;
}

void print_specific_tile(vector< pair<int,int> > v)
{
    cout<<endl;
    for(int i = 0; i< v.size(); i++)
    {
        printf(".___  ");
    }
    cout<<endl;
    for(int i = 0; i < v.size(); i++)
    {
        printf("|");
        printf("\033[%dm%2d\033[0m",v[i].first, v[i].second);
        printf("|  ");
    }
    cout<<endl;
    for(int i = 0; i< v.size(); i++)
    {
        printf("|__|  ");
    }
    cout<<endl;

}

void check_same_val()
{
    for(int i = 1;i <= 13; i++)
    {
        int count = 0;
        if(red_tiles[i] != 0) count++;
        if(yellow_tiles[i] != 0) count++;
        if(blue_tiles[i] != 0) count++;
        if(black_tiles[i] != 0) count++;
        if(3 <= count)
        {
            vector < pair<int,int> > color_check ;
            if(red_tiles[i] != 0) color_check.push_back(make_pair(RED, i));
            if(yellow_tiles[i] != 0) color_check.push_back(make_pair(YELLOW,i));
            if(blue_tiles[i] != 0) color_check.push_back(make_pair(BLUE,i));
            if(black_tiles[i] != 0) color_check.push_back(make_pair(BLACK,i));
            print_specific_tile(color_check);
            
        }
    }
}
void check_continue_val()
{
    vector<pair<int,int> > continue_check;

    for(int i = 1; i<= 14; i++)
    {
        if(i == 14 || red_tiles[i] == 0)
        {
            if(3 <= continue_check.size())
            {
                print_specific_tile(continue_check);
                continue_check.clear();
            }
            else
            {
                continue_check.clear();
            }
            
        }
        else continue_check.push_back(make_pair(RED,i));

    }
    for(int i = 1; i<= 14; i++)
    {
        if(i == 14 || blue_tiles[i] == 0)
        {
            if(3 <= continue_check.size())
            {
                print_specific_tile(continue_check);
                continue_check.clear();
            }
            else
            {
                continue_check.clear();
            }
            
        }
        else continue_check.push_back(make_pair(BLUE,i));

    }
    for(int i = 1; i<= 14; i++)
    {
        if(i == 14 || yellow_tiles[i] == 0)
        {
            if(3 <= continue_check.size())
            {
                print_specific_tile(continue_check);
                continue_check.clear();
            }
            else
            {
                continue_check.clear();
            }
            
        }
        else continue_check.push_back(make_pair(YELLOW,i));

    }
    for(int i = 1; i<= 14; i++)
    {
        if(i == 14 || black_tiles[i] == 0)
        {
            if(3 <= continue_check.size())
            {
                print_specific_tile(continue_check);
                continue_check.clear();
            }
            else
            {
                continue_check.clear();
            }
            
        }
        else continue_check.push_back(make_pair(BLACK,i));

    }

}

void game_end()
{
    cout<<
    "____ ____ _  _ ____    ____ _  _ ____ ____ \n"<<
    "| __ |__| |\\/| |___    |  | |  | |___ |__/ \n"<<
    "|__] |  | |  | |___    |__|  \\/  |___ |  \\ \n"<<endl;


}

int main(void)
{
    show_ascii_art();
    int button = -1;

    while(button != 0)
    {
        cout<<endl;
        cout<<"1: Initialize my tiles."<<endl;
        cout<<"2: show my tiles."<<endl;
        cout<<"3: Show the tiles I can submit using only my tiles."<<endl;
        cout<<"4: Show the tiles I can submit using tiles on table."<<endl;
        cout<<"5: Add new tiles in my tiles"<<endl;
        cout<<"6: Show tiles on the table"<<endl;
        cout<<"7: Write Laying My tiles on the table"<<endl;
        cout<<"8: Write Laying Others' tiles on the table"<<endl;
        cout<<"0: Exit the program"<<endl;
        cout<<"Press the button to do what you want. : ";
        cin>>button;
        if(button == 1)
        {
            cout<<"\n You pressed the button 1."<<endl;
            init();
            add_tiles();
            int num_of_total_tiles = num_of_red_tiles + num_of_yellow_tiles + num_of_blue_tiles + num_of_black_tiles;
            if (num_of_total_tiles == 14)
            {
                cout<<"Done."<<endl;
            }
            else
            {
                error_msg();
                init();
            }
            
        }
        else if(button == 2)
        {
            cout<<"\n You pressed the button 2."<<endl;
            print_user_tiles();
        }
        else if(button == 3)
        {
            cout<<"\n You pressed the button 3."<<endl;
            check_same_val();
            check_continue_val();
        }
        else if(button == 4)
        {
            cout<<"\n You pressed the button 4."<<endl;
            cout<<"It's not prepared. comming soon."<<endl;
        }
        else if(button == 5)
        {
            
            cout<<"\n You pressed the button 5."<<endl;
            add_tiles();
        }
        else if(button == 6)
        {
            cout<<"\n You pressed the button 6."<<endl;
            print_table_tiles();
        }
        else if(button == 7)
        {
            cout<<"\n You pressed the button 7."<<endl;
            add_table_tiles(true);
        }
        else if(button == 8)
        {
            cout<<"\n You pressed the button 8."<<endl;
            add_table_tiles(false);
        }
        else if(button == 0)
        {
            cout<<"You pressed the exit button."<<endl;
            game_end();
            break;
        }
        else
        {
            error_msg();
        }
        
    }
    
}