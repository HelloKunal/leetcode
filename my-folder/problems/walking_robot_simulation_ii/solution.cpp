class Robot {
public:
    int currX, currY;
    int currMov = 0;
    int currDir;
    int width, height;
    Robot(int width, int height) {
        currX = 0, currY = 0;
        currMov = 0, currDir = 1;
        this->width = width;
        this->height = height;
    }
    
    void move(int num) {
        currMov += num;
        currMov = (currMov) % (2*(height + width - 2));
        if(currMov == 0) {
            currX = 0;
            currY = 0;
            currDir = 4;
        } else if(currMov <= width-1) {
            currX = currMov;
            currY = 0;
            currDir = 1;
        } else if(currMov <= width+height-2) {
            currX = width-1;
            currY = currMov-(width-1);
            currDir = 2;
        } else if(currMov <= width+height+width-3) {   
            currY = height-1;         
            currX = (width-1)-(currMov-(width+height-2));
            currDir = 3;
        } else {
            currX = 0;
            currY = (height-1)-(currMov-(width+height+width-3));
            currDir = 4;
        }
    }
    
    vector<int> getPos() {
        return {currX, currY};
    }
    
    string getDir() {
        string res = "";
        switch(currDir) {
            case 1:
                res = "East";
                break;
            case 2:
                res = "North";
                break;
            case 3:
                res = "West";
                break;
            case 4:
                res = "South";
                break;
        }
        return res;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */