#include <stdio.h>
#include <stdlib.h>


struct stack
{
	int maxCapacityOfStack;
	int currNbrOfElementInStack;
	char *chars;
};

struct stack* newStack(int maxCapacityOfStack)
{
	struct stack *pointerStack = (struct stack*)malloc(sizeof(struct stack));

	pointerStack->maxCapacityOfStack = maxCapacityOfStack;
	pointerStack->currNbrOfElementInStack = -1;
	pointerStack->chars = (char*)malloc(sizeof(char) * maxCapacityOfStack);

	return pointerStack;
}

/**
 *  Pushes new char in the given stack
 *  @param newChar The char to be pushed.
 *  @param pointerStack, a pointer to the Stack.
 *  @return Void.
 */
void push(int newChar, struct stack *pointerStack)
{
	pointerStack->chars[++pointerStack->currNbrOfElementInStack] = newChar;
}


/**
 *  Pops the top char in the given stack
 *  @param pointerStack, a pointer to the Stack.
 *  @return Void.
 */
char pop(struct stack *pointerStack)
{
	return pointerStack->chars[pointerStack->currNbrOfElementInStack--];
}

/**
 *  Check if the given char is an
 *  opening parenthese of the form : (,<,{,[.
 *  @param charToCheck, the char to check.
 *  @return 1 if it is an opening parenthese, else 0.
 */
int isOpeningParenthese(char charToCheck){
    return(charToCheck == '{' || charToCheck == '(' || charToCheck == '['
        || charToCheck == '<');
}

/**
 *  Check if the given char is an
 *  opening parenthese of the form : ),>,},].
 *  @param charToCheck, the char to check.
 *  @return 1 if it is a closing parenthese, else 0.
 */
int isClosingParenthese(char charToCheck){
    return(charToCheck == '}' || charToCheck == ')' || charToCheck == ']'
        || charToCheck == '>');
}

/**
 *  Check if the two chars are matching
 *  parenthese of the form : (),<>,{},[].
 *  @param firstParenthese, the supposingly opening parenthese.
 *  @param secondParenthese, the supposingly closing parenthese.
 *  @return 1 the parentheses are indeed matching, else 0.
 */
int areParenthesesMatching(char firstParenthese, char secondParenthese){
    if (firstParenthese == '(' && secondParenthese == ')')
     return 1;
   else if (firstParenthese == '{' && secondParenthese == '}')
     return 1;
   else if (firstParenthese == '[' && secondParenthese == ']')
     return 1;
   else if (firstParenthese == '<' && secondParenthese == '>')
     return 1;
   else{
     return 0;
   }

}

/**
 *  Check if the given stack is empty
 *  @param pointerStack, a pointer to the Stack.
 *  @return 1 the stack is empty, else 0.
 */
int isStackEmpty(struct stack *pointerStack)
{
	return pointerStack->currNbrOfElementInStack == -1;
}

/**
 *  Check if a given expression is 'legal' by using
 *  a given stack
 *  @param sentenceToCheck, the expression to check.
 *  @param pointerStack, the stack that we will use in
 *  order to ceck the legality of sentenceToCheck
 *  @return 1 the expression is legal
 *  (according to the definition of legality of the exercice), else 0.
 */
int areParenthesesLegal(char sentenceToCheck[], struct stack *pointerStack)
{
    int i = 0;
    while (sentenceToCheck[i]) {
        if(isOpeningParenthese(sentenceToCheck[i])){
            push(sentenceToCheck[i], pointerStack);
        }
        if(isClosingParenthese(sentenceToCheck[i])){
            if(isStackEmpty(pointerStack)){
                return 0;
            }
            if(!areParenthesesMatching(pop(pointerStack),sentenceToCheck[i])){
                return 0;
            }
        }
        i++;
    }
    if(!isStackEmpty(pointerStack)){
        return 0;
    }
    return 1;

}
