import java.util.Map;
import java.util.HashMap;
import java.util.Arrays;
import java.util.Comparator;

class CustomComparator implements Comparator<Integer>
{
	Map<Integer, Integer> map;
	public CustomComparator(Map<Integer, Integer> map)
	{
		this.map = map;
	}
	
	public int compare(Integer x, Integer y)
	{
		if (map.containsKey(x) && map.containsKey(y))
			return map.get(x) - map.get(y);
		else if (map.containsKey(y))
			return 1;
		else if (map.containsKey(x))
			return -1;
		else
			return x - y;
	}
}

class CustomSort
{
	public static void main(String[] args)
	{
		// Wrapper class used
		Integer[] arr1 = { 5, 8, 9, 3, 5, 7, 1, 3, 4, 9, 3, 5, 1, 8, 4 };
		Integer[] arr2 = { 3, 5, 7, 2 };

		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		for(int i = 0; i < arr2.length; i++)
			map.put(arr2[i], i);
		
		// Arrays.sort method doesn't work with primitive array
		// when used with user defined comparator	
		Arrays.sort(arr1, new CustomComparator(map));
		
		for(Integer i : arr1)
			System.out.print(i + " ");
	}
}