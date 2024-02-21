// Stack 運用
// Auther : 陳柏妤
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int mat[100][2];
	int num, n;
	scanf("%d", &num);
	
	char sign;
	for(int i = 0; i < num; i++){
		cin >> sign;
		scanf("%d%d", &mat[sign-'A'][0], &mat[sign-'A'][1]);
	}
	string input;
	cin >> ws;
	while(getline(cin, input))
	{
		n = num;
		stack<char> st;
		int last, ans = 0;
		bool err = false;

		for(int i = 0; i < input.size(); i++){

			if(!st.empty() && st.top() != '(' && st.top() != ')' && input[i] != '('){ // stack頂端為字母且目前scan到字元為字母或 )，stack不為空，我很多判斷式都有寫到，防止無窮回圈
				last = input[i]-'A'; // last表示目前scan到字元

				if(input[i] == ')'){ // 目前scan到字元為 )，把字母取出，( pop掉，再將字母存回stack
					last = st.top()-'A'; // 也就是把 ...(M)... 改成 ...M...(...表示stack的樣子)
					st.pop();
	
					if(st.empty()){ // 可能讀到最後一個 ( 就空了，但還是要把字母存回去，後面還沒scan完
						st.push(last+'A');
						continue;
					}
				}

				if(!st.empty() && st.top() != '(' && mat[st.top()-'A'][1] == mat[last][0]){ // 前後為字母，可以做矩陣相乘，但要判斷矩陣能否相乘
					mat[n][0] = mat[st.top()-'A'][0];
					mat[n][1] = mat[last][1];
					ans += mat[n][0] * mat[n][1] * mat[st.top()-'A'][1];
					st.pop();
					last = n++;
				}
				else if(!st.empty() && st.top() == '('){ // 遇到 ( ， 直接pop掉
					st.pop();
				}
				else if(!st.empty()){ 
					err = true; // 前後字母矩陣大小不一，矩陣無法相乘
					break;
				}
				while(!st.empty() && st.top() != '(' && st.top() != ')'){ //和上面一樣前後為字母
					if(mat[st.top()-'A'][1] == mat[last][0]){
						mat[n][0] = mat[st.top()-'A'][0];
						mat[n][1] = mat[last][1];
						ans += mat[n][0] * mat[n][1] * mat[st.top()-'A'][1];
						st.pop();
						last = n++;
					}
					else{
						err = true;
						break;
					}
				}
				st.push((char)last+'A'); // 直到stack無法繼續pop，將矩陣相乘結果放回stack，接著繼續scan後面運算式
			}
			else {
				st.push(input[i]);
			}			
		}
		if(err){
			printf("error\n");
		}
		else{
			printf("%d\n", ans);
		}
	}
}
