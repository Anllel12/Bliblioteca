/*
/ 
*/

#include <iostream>
#include <vector>

using namespace std;

vector <string> teams;
vector <string> coachTeam;
vector <string> results;

string team;
string coach;
string result;

string f;

bool c = true;

void match(){
    cout << " Dime el nombre del equipo: \n";
    getline(cin, team);

    cout << " Dime el entrenador del equipo: \n";
    getline(cin, coach);

    teams.push_back(team);
    coachTeam.push_back(coach);
}

int main(int argc, char const *argv[])
{
    match();

    cout << "¿Quieres guardar un equipo mas?: \n";
    cin >> f;
    cin.ignore(100, '\n');

    while (c)
    {
        if (f.compare("s") == 0 || f.compare("S") == 0){

            match();

            cout << "¿Quieres guardar un equipo mas?: \n";
            cin >> f;
            cin.ignore(100, '\n');
        }
        else c = false;      
    }

    if (teams.size()%2 == 1){

        cout << "Son impares mete un valor mas.";

        match();

        for (int i = 0; i < teams.size(); i = i + 2)
        {
            cout << "Se enfrentan -> " << teams[i] << " contra ->" << teams [i+1] << endl;
        }
        for (int i = 0; i < teams.size(); i = i + 2)
        {
            cout << "El resultado -> " << teams[i] << " contra ->" << teams [i+1] << "ha sido: " << endl;
            getline(cin, result);

            results.push_back(result);
        }
    }
    else{
        for (int i = 0; i < teams.size(); i = i + 2)
        {
            cout << "Se enfrentan -> " << teams[i] << " contra ->" << teams [i+1] << endl;
        }
        for (int i = 0; i < teams.size(); i = i + 2)
        {
            cout << "El resultado -> " << teams[i] << " contra ->" << teams [i+1] << "ha sido: " << endl;
            getline(cin, result);

            results.push_back(result);
        }
    }

    return 0;
}