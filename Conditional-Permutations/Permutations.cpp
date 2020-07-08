#include <iostream>

#define OFFSET 1000

using namespace std;

string TT[10000];
string arr[10000][3];

int k = 0;
int setNum = 0;

string coeff[10][5] = {{"A", "C", "B", "C'", "B'"},
					   {"B", "C", "D", "C'", "D'"},
					   {"C", "D", "E", "D'", "E'"},
					   {"D", "E", "B", "E'", "B'"},
					   {"E", "D", "A", "D'", "A'"},
					   {"A'","B", "C", "B'", "C'"},
					   {"B'","D", "C", "D'", "C'"},
					   {"C'", "E", "D", "E'", "D'"},
					   {"D'", "B", "E", "B'", "E'"},
					   {"E'", "A", "D", "A'", "D'"}};

void show_coeff()
{
	for (int i = 0; i < 10; i++)
		cout << coeff[i][0] << ": " << coeff[i][1] << coeff[i][2] << coeff[i][3] << coeff[i][4] << endl;
	cout << endl;
}

int find_coeff(string j)
{
	for (int i = 0; i < 10; i++)
	{
		if (coeff[i][0] == j)
			return i;
	}
}


string A;
string B;
void var_1(string S, int BR)
{
	int i = 0;
	for (i = 0; i < S.length(); i++)
	{
		if ((int)S[i] >= 65 && (int)S[i] <= 90 || (int)S[i] >= 97 && (int)S[i] <= 122)
		{
			A = S[i];
			if (S[i + 1] == '\'')
			{
				A += S[i + 1];
			}

			i++;
			break;
		}
	}

	if (BR == 1) return;

	for (i; i < S.length(); i++)
	{
		if ((int)S[i] >= 65 && (int)S[i] <= 90 || (int)S[i] >= 97 && (int)S[i] <= 122)
		{
			B = S[i];
			if (S[i + 1] == '\'')
			{
				B += S[i + 1];
			}

			i++;
			break;
		}
	}
}

void expression(string exp, int r, string SSS);

void expand2(string S, int j, int flip, string SS){
	var_1(S, 1);
	TT[k++] = (A[1] != '\'') ? "{" + A + ": " + coeff[j][0] + SS + " , " + SS + "}" : "{" + A.substr(0, 1) + ": " + SS + " , " + coeff[j][0] + SS + "}";

}

void expand(string S, int j, int flip, string SS)
{
	if (S.substr(0, 2) == "((")
	{
		setNum++;
		if (S[S.length()-1] == '\'') j = (j + 5) % 10;

		if (flip)
		{
			if ((S[S.length() - 1] == '\''))
			{
				expression(S.substr(1, S.length() - 3), j, "");
			}
			else
			{
				expression(S.substr(1, S.length() - 2), j, "");
			}
		}
		else
		{
			if ((S[S.length() - 1] == '\''))
			{
				expression(S.substr(1, S.length() - 3), j, "");
			}
			else
			{
				expression(S.substr(1, S.length() - 2), j, /*SS.substr(1, SS.length() - 2)*/ "");
			}
		}
		setNum--;
	}
	else
	{
		var_1(S, 0);

		if (flip)
		{
			if (S[S.length() - 1] == '\'')
			{
				if (S[S.length()-1] == '\'') j = (j + 5) % 10;
				TT[k++] = (A[1] != '\'') ? "{" + A + ": " + coeff[j][1] + " , *}" : "{" + A.substr(0, 1) + ": * , " + coeff[j][1] + "}";
				TT[k++] = (B[1] != '\'') ? "{" + B + ": " + coeff[j][2] + " , *}" : "{" + B.substr(0, 1) + ": * , " + coeff[j][2] + "}";
				TT[k++] = (A[1] != '\'') ? "{" + A + ": " + coeff[j][3] + " , *}" : "{" + A.substr(0, 1) + ": * , " + coeff[j][3] + "}";
				TT[k++] = (B[1] != '\'') ? "{" + B + ": " + coeff[j][4] + SS + " , " + SS + "}" : "{" + B.substr(0, 1) + ": " + SS + " , " + coeff[j][4] + SS + "}";
			}
			else
			{
				TT[k++] = (A[1] != '\'') ? "{" + A + ": " + coeff[j][1] + " , *}" : "{" + A.substr(0, 1) + ": * , " + coeff[j][1] + "}";
				TT[k++] = (B[1] != '\'') ? "{" + B + ": " + coeff[j][2] + " , *}" : "{" + B.substr(0, 1) + ": * , " + coeff[j][2] + "}";
				TT[k++] = (A[1] != '\'') ? "{" + A + ": " + coeff[j][3] + " , *}" : "{" + A.substr(0, 1) + ": * , " + coeff[j][3] + "}";
				TT[k++] = (B[1] != '\'') ? "{" + B + ": " + coeff[j][4] + SS + " , " + SS + "}" : "{" + B.substr(0, 1) + ": " + SS + " , " + coeff[j][4] + SS + "}";

			}
		}
		else
		{
			if (S[S.length() - 1] == '\'')
			{
				if (S[S.length()-1] == '\'') j = (j + 5) % 10;
				TT[k++] = (A[1] != '\'') ? "{" + A + ": " + coeff[j][1] + " , *}" : "{" + A.substr(0, 1) + ": * , " + coeff[j][1] + "}";
				TT[k++] = (B[1] != '\'') ? "{" + B + ": " + coeff[j][2] + " , *}" : "{" + B.substr(0, 1) + ": * , " + coeff[j][2] + "}";
				TT[k++] = (A[1] != '\'') ? "{" + A + ": " + coeff[j][3] + " , *}" : "{" + A.substr(0, 1) + ": * , " + coeff[j][3] + "}";
				TT[k++] = (B[1] != '\'') ? "{" + B + ": " + coeff[j][4] + SS + " , " + SS + "}" : "{" + B.substr(0, 1) + ": " + SS + " , " + coeff[j][4] + SS + "}";
			}
			else
			{
				TT[k++] = (A[1] != '\'') ? "{" + A + ": " + coeff[j][1] + " , *}" : "{" + A.substr(0, 1) + ": * , " + coeff[j][1] + "}";
				TT[k++] = (B[1] != '\'') ? "{" + B + ": " + coeff[j][2] + " , *}" : "{" + B.substr(0, 1) + ": * , " + coeff[j][2] + "}";
				TT[k++] = (A[1] != '\'') ? "{" + A + ": " + coeff[j][3] + " , *}" : "{" + A.substr(0, 1) + ": * , " + coeff[j][3] + "}";
				TT[k++] = (B[1] != '\'') ? "{" + B + ": " + coeff[j][4] + " , *}" : "{" + B.substr(0, 1) + ": * , " + coeff[j][4] + "}";
			}
		}
	}
}

void set(int j, int i, int r, string SS)
{
	if (j == 1)
	{
		if (arr[i + OFFSET * setNum][2] == "1")
		{
			expand2(arr[i + OFFSET * setNum][0], r, 0, coeff[r][0] + SS);
		}
		else
		{
			expand(arr[i + OFFSET * setNum][0], r, 0, coeff[r][0] + SS);
		}
	}
	else if (j == 2)
	{
		if (arr[i + OFFSET * setNum][2] == "1")
			expand2(arr[i + OFFSET * setNum][0], find_coeff(coeff[r][1]), 0, coeff[r][1]);
		else
			expand(arr[i + OFFSET * setNum][0], find_coeff(coeff[r][1]), 0, coeff[r][1]);

		if (arr[i + 1 + OFFSET * setNum][2] == "1")
			expand2(arr[i + 1 + OFFSET * setNum][0], find_coeff(coeff[r][2]), 0, coeff[r][2]);
		else
			expand(arr[i + 1 + OFFSET * setNum][0], find_coeff(coeff[r][2]), 0, coeff[r][2]);

		if (arr[i + OFFSET * setNum][2] == "1")
			expand2(arr[i + OFFSET * setNum][0], find_coeff(coeff[r][3]), 1, coeff[r][3]);
		else if (arr[i + 1 + OFFSET * setNum][2] == "1")
			expand(arr[i + OFFSET * setNum][0], find_coeff(coeff[r][3]), 1, "");
		else
			expand(arr[i + OFFSET * setNum][0], find_coeff(coeff[r][3]), 1, coeff[r][3]);

		if (arr[i + 1 + OFFSET * setNum][2] == "1")
			expand2(arr[i + 1 + OFFSET * setNum][0], find_coeff(coeff[r][4]), 1, coeff[r][0]);
		else
			expand(arr[i + 1 + OFFSET * setNum][0], find_coeff(coeff[r][4]), 1, coeff[r][4] + SS);
	}
	else
	{
		set(j - (j / 2), i, find_coeff(coeff[r][1]), SS);
		set((j / 2), (i + (j / 2))+1, find_coeff(coeff[r][2]), SS);
		set(j - (j / 2), i, find_coeff(coeff[r][3]), SS);
		set((j / 2), (i + (j / 2))+1, find_coeff(coeff[r][4]), SS);

	}
}

void expression(string exp, int r, string SSS)
{
	int j = 0;
	int i = 0;
	int l = 0;

	TT[k++] = "{" + exp + ": " + coeff[r][0] + " , *}";
	cout << TT[--k] << endl;

	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '(')
		{
			arr[j + OFFSET * setNum][0] = arr[j + OFFSET * setNum][0] + exp[i];
			l++;
		}
		else if (exp[i] == '\0')
		{
			arr[j + OFFSET * setNum][1] = "*";
			break;
		}
		else if (exp[i] == ')')
		{
			l--;
			arr[j + OFFSET * setNum][0] = arr[j + OFFSET * setNum][0] + exp[i];

			if (l == 0)
			{
				if (exp[i + 1] == '\'')
				{
					arr[j + OFFSET * setNum][0] = arr[j + OFFSET * setNum][0] + exp[i + 1];
					i++;
				}
				arr[j + OFFSET * setNum][1] = "*";
				j++;
			}
		}
		else if (!(exp[i] == ' ' && l == 0))
		{
			arr[j + OFFSET * setNum][0] = arr[j + OFFSET * setNum][0] + exp[i];
			if ((int)exp[i] >= 65 && (int)exp[i] <= 90 || (int)exp[i] >= 97 && (int)exp[i] <= 122) {
				arr[j + OFFSET * setNum][2] += "1";
			}

		}
	}

	cout << endl;

	set(j, 0, r, SSS);

	for (int i = 0; i < j; i++){
		arr[i + OFFSET * setNum][0] = "";
		arr[i + OFFSET * setNum][1] = "";
	}

}

void preExp(string exp){
	expression(exp, 0, "");

}


int main()
{
	show_coeff();

	string exp = "(x z)' (x' y')'";
	//string exp = "(x' y')'";
	//string exp = "((x' y') (z'))'";
	//string exp = "((x y)' (x z)' (y x)')'";
	//string exp = "(x y)' (x z)' (y x)'";

	preExp(exp);

	for (int i = 0; i < k; i++)
		cout << "[" << i+1 << "]" << " " << TT[i] << endl;


	return 0;
}
