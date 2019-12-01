bool inbounds(int &attackX, int &attackY, int &currentScopeX, int &currentScopeY) {
	if (attackX > 0 && attackY > 0 && attackX <= currentScopeX && attackX <= currentScopeY) {
		return true;
	}
	else return false;
}