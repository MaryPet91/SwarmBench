package test;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Set;

public class TestComparator {

	public static void main(String[] args) {
		
		HashMap<String, String> tmp = new HashMap<>();
		tmp.put("7.3", "Value1");
		tmp.put("5.0", "Value2");
		tmp.put("1.3", "Value3");
		tmp.put("7.2", "Value4");
		tmp.put("2.3", "Value5");
		Set<String> key = tmp.keySet();
		List<Float> toSort = new ArrayList<Float>();
		
		for(String k: key)
			toSort.add(Float.parseFloat(k));
		
		Collections.sort(toSort,new MyComparator());
		
		for (int i = 0; i < toSort.size(); i++) {
			System.out.println(toSort.get(i).toString());
		}

	}
	
	

}


class MyComparator implements Comparator<Float> {

	@Override
	public int compare(Float o1, Float o2) {
		int esito=0;
		if(o1<o2)
			esito=-1;
		else if(o1>o2)
			esito=1;
		else
			esito=0;
		return esito;
	}

}
