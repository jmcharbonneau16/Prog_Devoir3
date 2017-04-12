/*
 * Nqueen.cpp
 *
 *  Created on: Apr 10, 2017
 *      Author: Jean-Michel
 */

#include "Nqueen.h"
#include <iostream>
#define n 4
using namespace std;

bool reine (int arr[n][n], int r) {
    if (r >= n){
        return true;
    }
    for (int c = 0; c < n; c++) {
    			if (arr[r][c] == 0) {
    				arr[r][c] = 9;
    				int d = 1;
    				for (int v = r + 1; v < n; v++) {
    					if (arr[v][c] == 0) {
    						arr[v][c] = r + 1;
    					}

    					if (c - d > -1) {
    						if (arr[v][c - d] == 0) {
    							arr[v][c - d] = r + 1;
    						}
    					}
    					if (c + d < n) {
    						if (arr[v][c + d] == 0) {
    							arr[v][c + d] = r + 1;
    						}
    					}
    					d++;
    				}
    				if (reine(arr, r + 1) == true) {
    					return true;
    				}
    				arr[r][c] = 0;
    				for (int i = r; i < n; i++) {
    					for (int j = 0; j < n; j++) {
    						if (arr[i][j] == r + 1) {
    							arr[i][j] = 0;
    						}
    					}
    				}
    			}

    		}
	return false;
}

int main()
{
  int echec[n][n];
  int i;
  int j;
  for (i = 0; i < n; i++){
	  for (j = 0; j < n; j++){
		  echec[i][j] = 0;
	  }
  }


  if (reine(echec, 0) == false){
      cout << "Aucune configuration n'existe";
  }else{
      cout << "Il est possible de placer les reines de manières qu'elles ne puissent s'attaquer";
      cout<<endl;

      for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
        	if(echec[i][j] == 9){
        	 cout << "D ";
        	}else{
        	cout <<"0 ";
        						}
      }
      cout<<endl;
    }
  }
}


