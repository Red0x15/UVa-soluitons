#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int main(){
  int big;
  char line[3000];
  string aux = "";
  scanf("%[^\n]s", line);
  while (getchar() != EOF) {
    int i;
    stack<string> pil;
    big = 0;
    for (i = 0; i < strlen(line); i++) {
      if (line[i] == '[' || line[i] == '{' || line[i] == '<'){
        aux += line[i];
        pil.push(aux);
        aux = "";
      }
      else if (line[i] == '('){
        if (i < strlen(line) - 1 && line[i + 1] == '*'){
          aux += "(*";
          i++;
        }
        else{
          aux += line[i];
        }
        pil.push(aux);
        aux = "";
      }
      else if (line[i] == ']' || line[i] == '}' || line[i] == '>' || line[i] == ')' || line[i] == '*'){
        if (pil.empty() && line[i] != '*'){
          aux += line[i];
          aux = "";
          pil.push(aux);
          big++;
          break;
        }
        else if (line[i] == ']'){
          if (pil.top() == "["){
            pil.pop();
          }
          else{
            big++;
            break;
          }
        }
        else if (line[i] == '}'){
          if (pil.top() == "{"){
            pil.pop();
          }
          else{
            big++;
            break;
          }
        }
        else if (line[i] == '>'){
          if (pil.top() == "<"){
            pil.pop();
          }
          else{
            big++;
            break;
          }
        }
        else if (line[i] == '*'){
           if (i < strlen(line) - 1 && line[i + 1] == ')'){
             if (pil.empty()){
               aux = "*)";
               pil.push(aux);
               aux = "";
               big++;
               break;
             }
             else if (pil.top() == "(*"){
               pil.pop();
             }
             else{
               big++;
               break;
             }
             i++;
           }
        }
        else if (line[i] == ')'){
          if (pil.top() == "("){
            pil.pop();
          }
          else{
            big++;
            break;
          }
        }
      }
      big++;
    }
    int j = 0;
    while (line[j] == ' ') {
      j++;
    }
    if(j == strlen(line) - 1){
      cout << "YES" << endl;
    }
    else{
      if (i == strlen(line) || strlen(line) == 1){
        big++;
      }
      if (pil.empty()){
        cout << "YES" << endl;
      }
      else{
        cout << "NO " << big << endl;
      }
    }
    scanf("%[^\n]s", line);
  }
  return 0;
}
