package com.company;

public class ElementMatcher<T> {
    private T element;

    public ElementMatcher(T ele){
        this.element = ele;
    }

    public <T> boolean match(T ele) {
        return this.element == ele;
    }
}
