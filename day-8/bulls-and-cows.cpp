class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        
        int secretFreq[10] ={0};
        int guessFreq[10] = {0};
        
        for(int i = 0; i < secret.size(); i++) {
            if(secret[i] == guess[i]) {
                bulls++;
                continue;
            }
            secretFreq[(int) (secret[i] - '0')]++;
            guessFreq[(int) (guess[i] - '0')]++;
        }
        
        for(int i = 0; i < 10; i++) {
            cows += min(secretFreq[i], guessFreq[i]);
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};