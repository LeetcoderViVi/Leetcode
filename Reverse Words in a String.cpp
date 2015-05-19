class Solution {
public:
    void reverseWords(string &s) {
        stack<string> stackStr;
		string tempStr="";
		int tag=0;
		if(s.size()==0)
			return;
		//push the words into stack
		for(int i=0;i<s.size();i++)
		{
			if(s[i]==' ')
			{
				if(tag==1)
				{
					tag=0;
					stackStr.push(tempStr);
				}
				continue;
			}
			if(s[i]!=' ')
			{
				if(tag==0)
				{
					tempStr = s[i];
					tag = 1;
				}
				else if(tag==1)
					tempStr += s[i];
			}
		}

		if(tag==1)
			stackStr.push(tempStr);

		//pop the words out of the stack
		if(stackStr.empty())
		{s = "";return;}
		s = stackStr.top();
		stackStr.pop();
		while(!stackStr.empty())
		{
			s +=' ';
			s += stackStr.top();
			stackStr.pop();
		}
    }
};
