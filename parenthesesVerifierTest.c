#include "parenthesesVerifier.c"

/**
 *  Check if all words of a list of valid/invalid expression are indeed
 *  valid/invalid, using the function areParenthesesLegal
 *  a given stack.
 *  Print a message if an expression was not juged correctly
 *  @param numberOfWords, the nub;er of words in listOfWords.
 *  @param listOfWords, a list of words the we want to check validity or invalidity
 *  @param areLegalWords, a flag telling us if our given listOfWords
 *  is comprised of legal or illegal words
 *  @return 1 all expressions in listOfWords gave the right
 *  output using the function areParenthesesLegal
 */
int runTestsOnListOfWord(int numberOfWords, char listOfWords[][100], int areLegalWords)
{
    int i=0;
    for( i = 0; i < numberOfWords; i++)
    {
        if(areLegalWords){
            if(!areParenthesesLegal(listOfWords[i], newStack(100))){
            printf("test failed on word \"%s\", it should be an illegal word\n", listOfWords[i]);
            return 0;
            }
        }
        else{
            if(areParenthesesLegal(listOfWords[i], newStack(100))){
            printf("test failed on word \"%s\", it should be a legal word\n", listOfWords[i]);
            return 0;
            }
        }
    }
    return 1;
}


/**
 *  main test fuction for bonus,
 *  here you can easily add a word in the array LegalExpressions or
 *  IllegalExpressions according to its validity and then the
 *  function will check if our areParenthesesLegal fuction works well
 *  prints a message if everything went well.
 */
int main()
{
    int MAX_STRING_SIZE = 100;

    char LegalExpressions[][100] = {"(3)", "([])", "(()A([]))",
    "<({<>{}})[]>", "", "14"};

    char IllegalExpressions[][100]  = {")", "[)", "<]>", "{", "())" };


    int numberOfLegalWords = sizeof(LegalExpressions) / sizeof(LegalExpressions[0]);
    int numberOfIllegalWords = sizeof(IllegalExpressions) / sizeof(IllegalExpressions[0]);

    if(runTestsOnListOfWord(numberOfLegalWords,LegalExpressions, 1)
        && runTestsOnListOfWord(numberOfIllegalWords, IllegalExpressions, 0)){
        printf("All tests passed! congrats!\n");
    }
    return 0;



}
