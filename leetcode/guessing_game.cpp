/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        unsigned long int start = 1;
        unsigned long int end = n;
        unsigned long int res = 1;

        while (guess(res) != 0) {
            res = (start + end) / 2;
            
            if (guess(res) == -1) {
                end = res - 1;
            }

            else {
                start = res + 1;
            }
        }

        return res;
    }
};