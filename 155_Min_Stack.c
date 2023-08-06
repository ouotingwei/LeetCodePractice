typedef struct {
    int value;
    int min;
} StackNode;

typedef struct {
    StackNode* nodes;
    int topIndex;
    int capacity;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate() {
    MinStack* stack = (MinStack*)malloc(sizeof(MinStack));
    stack->capacity = 10000; 
    stack->nodes = (StackNode*)malloc(stack->capacity * sizeof(StackNode));
    stack->topIndex = -1;
    return stack;
}

void minStackPush(MinStack* obj, int val) {
    obj->topIndex++;
    obj->nodes[obj->topIndex].value = val;
    if (obj->topIndex == 0) {
        obj->nodes[obj->topIndex].min = val;
    } else {
        obj->nodes[obj->topIndex].min = val < obj->nodes[obj->topIndex - 1].min ? val : obj->nodes[obj->topIndex - 1].min;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->topIndex >= 0) {
        obj->topIndex--;
    }
}

int minStackTop(MinStack* obj) {
    return obj->nodes[obj->topIndex].value;
}

int minStackGetMin(MinStack* obj) {
    return obj->nodes[obj->topIndex].min;
}

void minStackFree(MinStack* obj) {
    free(obj->nodes);
    free(obj);
}
