string encode(string src)
{ 
    string output = "";
    char prevChar = src[0];
    int currCount = 1;

    for(int i = 1; i < src.size(); i++) {
        char c = src[i];
        if(c == prevChar) {
            currCount++;
        } else {
            output += (prevChar + to_string(currCount));
            currCount = 1;
        }
        
        prevChar = src[i];
    }
    output += (prevChar + to_string(currCount));
    return output;
}     
 