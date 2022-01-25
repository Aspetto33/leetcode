class MedianFinder {
public:
    // ���ѣ��洢���һ������ݣ��Ѷ�Ϊ���ֵ
    priority_queue<int, vector<int>, less<int>> maxHeap;
    // ��С�ѣ� �洢�ұ�һ������ݣ��Ѷ�Ϊ��Сֵ
    priority_queue<int, vector<int>, greater<int>> minHeap;
    /** initialize your data structure here. */
    MedianFinder() {
    }

    // ά�ֶ�����ƽ�⣬����֤��߶ѵ����ֵС�ڻ�����ұ߶ѵ���Сֵ
    void addNum(int num) {
        /*
         * �����ѵ����ݸ������ʱ����߶����Ԫ�ء�
         * ���õķ�������ֱ�ӽ����ݲ�����߶ѣ����ǽ������Ȳ����ұ߶ѣ��㷨������
         * ���Ѷ������ݲ��뵽��߶ѣ�������֤��߶Ѳ����Ԫ��ʼ�����ұ߶ѵ���Сֵ��
         * ͬ��������ݶ࣬���ұ߶�������ݵ�ʱ���Ƚ����ݷ�����߶ѣ�ѡ�����ֵ�ŵ��ұ߶��С�
         */
        if (maxHeap.size() == minHeap.size()) {
            minHeap.push(num);
            int top = minHeap.top();
            minHeap.pop();
            maxHeap.push(top);
        } else {
            maxHeap.push(num);
            int top = maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top()+minHeap.top())*1.0/2;
        } else {
            return maxHeap.top()*1.0;
        }
    }
};