#include <iostream>
using namespace std;

int solver(int kids, int sum_of_candy) {
    return sum_of_candy % kids;
}

void reader(int no_of_lines) {
    int bag = 0;
    int kids = 0;
    int sum_of_candy = 0;
    int result = 0;
    int index = 1;
    no_of_lines *= 2;

    for(int i = 1; i <= no_of_lines; i++) {
        //check odd
        if(i%2 != 0)
            cin >> bag >> kids;

        //check even
        else {
            for(int j = 0; j != bag; j++) {
                int temp = 0;
                cin >> temp;
                sum_of_candy += temp;
            }
                result = solver(kids, sum_of_candy);
                cout << "Case #" << index++ << ": " << result << endl;
                sum_of_candy = 0;
            }
        } // end of big for loop
}

int main() {
    int no_of_lines = 0;
    cin >> no_of_lines;
    reader(no_of_lines);
    
    return 0;
}
