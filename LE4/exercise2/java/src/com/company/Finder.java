package com.company;

import java.util.Iterator;
import java.util.regex.Matcher;

public class Finder {
    public static void findIf(Iterator iter, Matcher matcher) {

        String text    =
            "This is the text to be searched " +
            "for occurrences of the http:// pattern.";

        while(iter.hasNext()) {
            if(matcher.matches()
        }
    }
}
