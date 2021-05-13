int maxProfit(int* prices, int pricesSize){
    int max_profit = 0, min_so_far = INT_MAX;
    for (int i = 0; i < pricesSize; ++i) {
        int day_profit = prices[i] - min_so_far;
        max_profit = day_profit > max_profit ? day_profit : max_profit;
        min_so_far = prices[i] < min_so_far ? prices[i] : min_so_far;
    }
    return max_profit;
}
