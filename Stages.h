
//First part with different tracks
void stage1(){
//Stop 1
	lfToBlack(blackLine, left);

	//Skift spor
	turnDeg(-30);
	JumpLine(1);
	lfToBlack(55, left);
	turnDeg(30);

	//Stop 2
	lfToBlack(blackLine, left);

	//Skift spor
	turnDeg(30);
	JumpLine(1);
	lfToBlack(55, left);
	turnDeg(-10);
}
