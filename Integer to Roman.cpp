//Solution 1.
class Solution {
public:
    string intToRoman(int num) {
        if(num<=0)
			return "";
		//unordered_map to store the information.
		unordered_map<int,char> umic;
		stack<char> sc;
		umic[1]='I';
		umic[5]='V';
		umic[10]='X';
		umic[50]='L';
		umic[100]='C';
		umic[500]='D';
		umic[1000]='M';
		int rem=0,iter=1;
		while(num)
		{
			rem = num%10;
			if(rem==0)
			{
				iter*=10;
				num/=10;
				continue;
			}
			if(rem/5==0)
			{
				if(rem%5<=3)
					for(int i=0;i<rem%5;i++)
						sc.push(umic[iter]);
				else if(rem%5==4)
				{
					sc.push(umic[iter*5]);
					sc.push(umic[iter]);
				}
			}
			else if(rem/5==1)
			{
				if(rem%5<=3)
				{
					for(int i=0;i<rem%5;i++)
						sc.push(umic[iter]);
					sc.push(umic[iter*5]);
				}
				else if(rem%5==4)
				{
					sc.push(umic[iter*10]);
					sc.push(umic[iter]);
				}
			}
			num /= 10;
			iter*=10;
		}
		string result="";
		while(!sc.empty())
		{
			result += sc.top();
			sc.pop();
		}
		return result;
    }
};
// Solution 2.
String[] romanPieces={"","I","II","III","IV","V","VI","VII","VIII","IX", "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC", "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM", "","M","MM","MMM","MMMM"}; 
return romanPieces[num/1000+30]+romanPieces[(num/100)%10+20] +romanPieces[(num/10)%10+10]+romanPieces[num%10];
