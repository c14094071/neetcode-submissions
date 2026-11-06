import heapq
class MedianFinder:

    def __init__(self):
        self.min_heap = []##放大的
        self.max_heap = []##放小的
        

    def addNum(self, num: int) -> None:
        if((len(self.max_heap)!=0 and num>(0-self.max_heap[0]))):
            heapq.heappush(self.min_heap, num)    
        else :
            heapq.heappush(self.max_heap, 0-num) ##轉負號用在max_heap

        if(len(self.max_heap)<len(self.min_heap)):
            heapq.heappush(self.max_heap,0-self.min_heap[0]) ## 查最上方的值[0] 
            heapq.heappop(self.min_heap)
        if(len(self.max_heap) > len(self.min_heap)+1):
            heapq.heappush(self.min_heap, 0- self.max_heap[0])
            heapq.heappop(self.max_heap)
        

    def findMedian(self) -> float:
        
        size = len(self.min_heap)+ len(self.max_heap)
        if(size==0): return null
        if(size%2==0):
            return (self.min_heap[0]+(-self.max_heap[0]))/2
        else:
            return 0-self.max_heap[0]


        


        
        