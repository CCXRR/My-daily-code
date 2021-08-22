#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void Hanoi(int layer, char A, char B, char C, int* count)
{
	if (layer == 1)
	{
		printf("move %c => %c\n", A, C);
		*count += 1;
	}
	else
	{
		Hanoi(layer - 1, A, C, B, count);
		printf("move %c => %c\n", A, C);
		*count += 1;
		Hanoi(layer - 1, B, A, C, count);
	}
}

/*					initial
		  |
		  |
		 [|]	  ...
		[ | ]     n-1
	   [  |  ]    ...
	  [   |   ]    n
   =======|=======
		  A

		  |
		  |
		  |
		  |
		  |
   =======|=======
		  B

		  |
		  |
		  |
		  |
		  |
   =======|=======
		  C
					first: from A move n-1 through C -> B
		  |
		  |
		  |
		  |
	  [   |   ]    n
   =======|=======
		  A

		  |
		  |
		 [|]	  ...
		[ | ]	  n-1
	   [  |  ]    ...
   =======|=======
		  B

		  |
		  |
		  |
		  |
		  |
   =======|=======
		  C
					second: from A move n -> C
		  |
		  |
		  |
		  |
		  |
   =======|=======
		  A

		  |
		  |
		 [|]	  ...
		[ | ]	  n-1
	   [  |  ]    ...
   =======|=======
		  B

		  |
		  |
		  |
		  |
	  [   |   ] n
   =======|=======
		  C
					third: from B move n-1 through B -> C
		  |
		  |
		  |
		  |
		  |
   =======|=======
		  A

		  |
		  |
		  |
		  |
		  |
   =======|=======
		  B

		  |
		  |
		 [|]	  ...
		[ | ]     n-1
	   [  |  ]    ...
	  [   |   ]    n
   =======|=======
		  C
*/