#include "../inc/Sudoku.h"

Sudoku::Sudoku(){
	Board = NULL;
	size = 9;
	InitBoard();
	ResetBoard();
}

Sudoku::~Sudoku(){
	for (int i = 0; i < size; i++) delete [] Board[i];
    delete [] Board;
};

void Sudoku::InitBoard(){
	Board = new int*[size];
    for (int i = 0; i < size; i++) Board[i] = new int[size];
};

void Sudoku::ResetBoard(){
	for(int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
		    Board[i][j] = 0;
		}
	}
}

void Sudoku::ListFreeRecords(){
    Elem elem;
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if (Board[i][j] == 0){
				elem.I(i); elem.J(j);
			    elem.V(Board[i][j]);
				Rec.push_back(elem);
			}
		}
	}
};

bool Sudoku::Check(int _i, int _j, int _v){
	bool conf = false;

	for (int i = 0; i < size; i++){
		if (ReturnArrayElement(_i,i) == _v){
		    conf = true;
		}
	}

	for (int j = 0; j < size; j++){
		if (ReturnArrayElement(j,_j) == _v){
		    conf = true;
		}
	}

        if (((_i+1)%3) == 0){
            if (((_j+1)%3) == 0){
                for (int m = _i - 2; m < _i + 1; m++){
                    for (int l = _j - 2; l < _j + 1; l++){
                        if (ReturnArrayElement(m,l) == _v){
		                    conf = true;
		                }
                    }
                }
            }
            if (((_j+1)%3) == 2){
             for (int m = _i - 2; m < _i + 1; m++){
                 for (int l = _j-1; l < _j + 2; l++){
                     if (ReturnArrayElement(m,l) == _v){
		                    conf = true;
		             }
                 }
             }
         }
         if (((_j+1)%3) == 1){
             for (int m = _i - 2; m < _i + 1; m++){
                 for (int l = _j; l < _j + 3; l++){
                     if (ReturnArrayElement(m,l) == _v){
		                    conf = true;
		             }
                 }
             }
         }
     }

     if (((_i+1)%3) == 2){
         if (((_j+1)%3) == 0){
             for (int m = _i - 1; m < _i + 2; m++){
      	    	 for (int l = _j - 2; l < _j + 1; l++){
                     if (ReturnArrayElement(m,l) == _v){
		                    conf = true;
		             }
          		 }
             }
         }
         if (((_j+1)%3) == 2){
             for (int m = _i-1; m < _i + 2; m++){
                 for (int l = _j - 1; l < _j + 2; l++){
                     if (ReturnArrayElement(m,l) == _v){
		                    conf = true;
		             }
                 }
             }
         }
         if (((_j+1)%3) == 1){
             for (int m = _i - 1; m < _i + 2; m++){
				 for (int l = _j; l < _j + 3; l++){
					 if (ReturnArrayElement(m,l) == _v){
		                    conf = true;
		             }
				 }
			 }
		 }
	 }

	 if (((_i+1)%3) == 1){
		 if (((_j+1)%3) == 0){
			 for (int m = _i; m < _i + 3; m++){
				 for (int l = _j - 2; l < _j + 1; l++){
					 if (ReturnArrayElement(m,l) == _v){
		                    conf = true;
		             }
				 }
			 }
		 }
		 if (((_j+1)%3) == 2){
			 for (int m = _i; m < _i + 3; m++){
				 for (int l = _j - 1; l < _j + 2; l++){
					 if (ReturnArrayElement(m,l) == _v){
		                    conf = true;
		             }
				 }
			 }
		 }
		 if (((_j+1)%3) == 1){
			 for (int m = _i; m < _i + 3; m++){
				 for (int l = _j; l < _j + 3; l++){
					 if (ReturnArrayElement(m,l) == _v){
		                    conf = true;
		             }
				 }
			 }    
		 }                               
	 }

	 return conf;
};

void Sudoku::BT(){
	int kk, u;
	bool cond = false;
	std::list<Elem>::iterator Iter;
	for (Iter = Rec.begin(); Iter != Rec.end(); ){
		cond = false;
		u = Iter->V();
		for (int k = size; k > u; k--){
			if (!Check(Iter->I(),Iter->J(),k)){
				kk = Iter->V();
				Iter->V(k);
				cond = true;
			}
		}
		if (cond == false){
			Iter->V(0);
			Board[Iter->I()][Iter->J()] = Iter->V();
			--Iter;
		} 
		else{
			Board[Iter->I()][Iter->J()] = Iter->V();
			++Iter;
		}
		//ShowBoard();
	} 
};

void Sudoku::ShowBoard(){
	std::cout << std::endl;
	for (int k = 0; k < (2*(size + 4) - 1); k++){
		if ( k == 0) std::cout << " ";
	    std::cout << "-";
	} 
	std::cout << std::endl;
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if ( j == 0) std::cout << " |";
			std::cout << " " << Board[i][j];
			if ( (j == 2) || (j == 5) || (j == 8)){
			    std::cout << " |";
			}
		} 
		std::cout << std::endl;
		if ( (i == 2) || (i == 5) || (i == 8)){
		    for (int k = 0; k < (2*(size + 4) - 1); k++){
				if ( k == 0) std::cout << " ";
	            std::cout << "-";
			}
		} 
		std::cout << std::endl;
	} 
	std::cout << std::endl;
};