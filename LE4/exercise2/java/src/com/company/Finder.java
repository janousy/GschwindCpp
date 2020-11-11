package com.company;

import java.util.Iterator;
import java.util.regex.Matcher;


public class Finder<T> {

        public static <T> Iterator<T> findIf(Iterator<T> it, ElementMatcher<T> matcher){
        while(it.hasNext()){
            if(matcher.match(it.next())){
                return it;

            }
        }
        return null;
    }
}
