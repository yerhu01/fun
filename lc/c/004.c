int maxArea(int* height, int heightSize){
    int ret = 0;
    int l = 0, r = heightSize-1;
    while (l < r) {
        int h = height[l] < height[r] ? height[l] : height[r];
        int w = r-l;
        int area = h * w;
        ret = area > ret ? area : ret;
        if (height[l] < height[r])
            ++l;
        else
            --r;
    }
    return ret;
}
