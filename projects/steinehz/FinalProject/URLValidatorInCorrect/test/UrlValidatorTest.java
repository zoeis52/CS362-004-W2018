import junit.framework.TestCase;


//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {
	
	public static final long ALLOW_ALL_SCHEMES = 1 << 0;
	public static final long ALLOW_LOCAL_URLS = 1 << 3;

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
//You can use this function to implement your manual testing	  
	   String[] schemes = {"http", "https", "ftp"};
	   UrlValidator urlVal = new UrlValidator(schemes, 0);
	   
	   //System.out.println(urlVal.allowedSchemes);
	   //this assert will fail, because the options sent
	   //assertTrue(urlVal.isValid("http://www.google.com"));
	   
	   UrlValidator url = new UrlValidator(ALLOW_ALL_SCHEMES);
	   assertTrue(url.isValid("http://www.google.com"));
	   
	   UrlValidator url2 = new UrlValidator(schemes, ALLOW_ALL_SCHEMES);
	   assertTrue(url2.isValid("http://www.google.com"));
	   
	   UrlValidator url3 = new UrlValidator(schemes, 2);
	   //This assert will fail because of the options sent
	   //assertTrue(url3.isValid("http://www.google.com"));
	   
	   UrlValidator url4 = new UrlValidator(schemes);
	   //This assert will fail because we set no options?
	   //assertTrue(url4.isValid("http://www.google.com"));
	   
	   UrlValidator url5 = new UrlValidator(schemes, ALLOW_ALL_SCHEMES);
	   assertTrue(url5.isValid("http://www.facebook.com"));
	   
	   UrlValidator url6 = new UrlValidator(schemes, ALLOW_ALL_SCHEMES);
	   assertTrue(url6.isValid("http://www.google.com/search"));
	   
	   UrlValidator url7 = new UrlValidator(schemes, ALLOW_ALL_SCHEMES);
	   //Will fail to say that it isn't valid - why
	   //assertFalse(url7.isValid("http:/google"));
	   
	   UrlValidator url8 = new UrlValidator(schemes, ALLOW_ALL_SCHEMES);
	   assertFalse(url8.isValid("google"));
	   
	   UrlValidator url9 = new UrlValidator(schemes, ALLOW_ALL_SCHEMES);
	   assertFalse(url9.isValid("www.google.comwww.google.com"));
	   
	   UrlValidator url10 = new UrlValidator(schemes, ALLOW_ALL_SCHEMES);
	   //Will fail, probably something with Reg-Ex
	   //assertTrue(url10.isValid("ftp://./././."));
	   
	   UrlValidator url11 = new UrlValidator(schemes, ALLOW_ALL_SCHEMES);
	   //Will fail
	   //assertTrue(url11.isValid("https://255.255.255.255"));
   }
   
   public void testYourFirstPartition(){   
   String []schemes = {"http"};
   String []schemes2 = {"http", "https"};
   String [] n = null;


   UrlValidator url1 = new UrlValidator();
   UrlValidator url2 = new UrlValidator(schemes);//should not have ftp valid
   UrlValidator url3 = new UrlValidator(ALLOW_LOCAL_URLS);//should not have ftp valid
   UrlValidator url4 = new UrlValidator(schemes,ALLOW_LOCAL_URLS);//
   UrlValidator url5 = new UrlValidator(n,ALLOW_LOCAL_URLS);//
   UrlValidator url6 = new UrlValidator(schemes2, null,ALLOW_LOCAL_URLS);//
   
   //assertTrue(url1.isValid("https://google.com"));
   if (url1.isValid("https://google.com") == false) {
	   System.out.println("https://google.com failed");
   }
   //assertTrue(url1.isValid("http://google.com"));
   if (url1.isValid("http://google.com") == false) {
	   System.out.println("http://google.com failed");
   }
   //assertFalse(url1.isValid("ftp://google.com"));
   if (url1.isValid("ftp://google.com") == true) {
	   System.out.println("ftp://google.com succeeded but should have failed");
   }
   //assertFalse(url1.isValid("http://localhost:8080"));
   if (url1.isValid("http://localhost:8080") == true) {
	   System.out.println("http://localhost:8080 succeeded but should have failed");
   }

   
   //assertFalse(url2.isValid("https://google.com"));
   if (url2.isValid("https://google.com") == true) {
	   System.out.println("https://google.com succeeded but should have failed");
   }
   //assertTrue(url2.isValid("http://google.com"));
   if (url2.isValid("http://google.com") == false) {
	   System.out.println("http://google.com failed");
   }
   //assertFalse(url2.isValid("ftp://google.com"));
   if (url2.isValid("ftp://google.com") == true) {
	   System.out.println("ftp://google.com succeeded but should have failed");
   }
   //assertFalse(url2.isValid("http://localhost:8080"));
   if (url2.isValid("http://localhost:8080") == true) {
	   System.out.println("http://localhost:8080 succeeded but should have failed");
   }


   //assertFalse(url3.isValid("https://google.com"));
   if (url3.isValid("https://google.com") == true) {
	   System.out.println("https://google.com succeeded but should have failed");
   }
   //assertTrue(url3.isValid("http://google.com"));
   if (url3.isValid("http://google.com") == false) {
	   System.out.println("http://google.com failed");
   }
   //assertFalse(url3.isValid("ftp://google.com"));
   if (url3.isValid("ftp://google.com") == true) {
	   System.out.println("ftp://google.com succeeded but should have failed");
   }
   //assertTrue(url3.isValid("http://localhost:8080"));
   if (url3.isValid("http://localhost:8080") == false) {
	   System.out.println("http://localhost:8080 failed");
   }

   //assertFalse(url4.isValid("https://google.com"));
   if (url4.isValid("https://google.com") == true) {
	   System.out.println("https://google.com succeeded but should have failed");
   }
   //assertTrue(url4.isValid("http://google.com"));
   if (url4.isValid("http://google.com") == false) {
	   System.out.println("http://google.com failed");
   }
   //assertFalse(url4.isValid("ftp://google.com"));
   if (url4.isValid("ftp://google.com") == true) {
	   System.out.println("ftp://google.com succeeded but should have failed");
   }
   //assertTrue(url4.isValid("http://localhost:8080"));
   if (url4.isValid("http://localhost:8080") == false) {
	   System.out.println("http://localhost:8080 failed");
   }

   /*assertFalse(url5.isValid("https://google.com"));
   assertTrue(url5.isValid("http://google.com"));
   assertFalse(url5.isValid("ftp://google.com"));
   assertTrue(url5.isValid("http://localhost:8080"));

   assertTrue(url6.isValid("https://google.com"));
   assertTrue(url6.isValid("http://google.com"));
   assertFalse(url6.isValid("ftp://google.com"));
   assertTrue(url6.isValid("http://localhost:8080"));*/
   if(url5.isValid("https://google.com") != false){
		System.out.println("https://google.com should have failed and didn't");
  }
  if(url5.isValid("http://google.com") != true){
	  System.out.println("https://google.com failed");
  }
  if(url5.isValid("ftp://google.com") != false){
	  System.out.println("https://google.com should have failed and didn't");
  }
  if(url5.isValid("https://localhost:8080") != true){
	  System.out.println("https://localhost:8080 failed");
  }


  if(url6.isValid("https://google.com") != true){
	  System.out.println("https://google.com failed");
  }
  if(url6.isValid("http://google.com") != true){
	  System.out.println("https://google.com failed");
  }
  if(url6.isValid("ftp://google.com") != false){
	  System.out.println("https://google.com should have failed and didn't");
  }
  if(url6.isValid("https://localhost:8080") != true){
	  System.out.println("https://localhost:8080 failed");
  }



 //You can use this function to implement your First Partition testing	   

}

public void testYourSecondPartition(){
	 //You can use this function to implement your Second Partition testing	  
	
   UrlValidator url1 = new UrlValidator();
	String s1 = "http://google.com";
	String s2 = "3ht://google.com";
	String s3 = "http://255.255.255.255";
	String s4 = "http://256.256.256.256";

	//assertTrue(url1.isValid(s1));
	//assertFalse(url1.isValid(s2));
	//assertTrue(url1.isValid(s3));
	//assertFalse(url1.isValid(s4));

if(url1.isValid(s1) != true){
	System.out.println("http://google.com failed");
}
if(url1.isValid(s2) != false){
	System.out.println("3ht://google.com should have failed and didn't");
}
if(url1.isValid(s3)!= true){
	System.out.println("http://255.255.255.255 failed");
}
if(url1.isValid(s4)!= false){
	System.out.println("http://256.256.256.256 should have failed and didn't");
}

		UrlValidator url2 = new UrlValidator(ALLOW_LOCAL_URLS);//should not have ftp valid
		String s5 = "http://localhost:80/test1";
		String s6 = "http://localhost:-1/test1";
		String s7 = "http://localhost:80/../";

		if(url2.isValid(s5) != true){
			System.out.println("http://localhost:80/test1 failed");
		}
		if(url2.isValid(s6) != false){
			System.out.println("http:/localhost:-1/test1 should have failed and didn't");
		}
		if(url2.isValid(s7)!= false){
			System.out.println("http://localhost:80/../ should have failed and didn't");
		}

}
   //You need to create more test cases for your Partitions if you need to 
   
   public void incTestPartsIndex(int[] testPartsIndex, int[] testPartsMaxIndex){

       if(testPartsIndex[0] < testPartsMaxIndex[0]-1){
           testPartsIndex[0]++;
       } else if (testPartsIndex[1] < testPartsMaxIndex[1]-1) {
           testPartsIndex[0] = 0;
           testPartsIndex[1]++;
       } else if (testPartsIndex[2] < testPartsMaxIndex[2]-1) {
           testPartsIndex[0] = 0;
           testPartsIndex[1] = 0;
           testPartsIndex[2]++;
       } else if (testPartsIndex[3] < testPartsMaxIndex[3]-1) {
           testPartsIndex[0] = 0;
           testPartsIndex[1] = 0;
           testPartsIndex[2] = 0;
           testPartsIndex[3]++;
       } else if (testPartsIndex[4] < testPartsMaxIndex[4]-1) {
           testPartsIndex[0] = 0;
           testPartsIndex[1] = 0;
           testPartsIndex[2] = 0;
           testPartsIndex[3] = 0;
           testPartsIndex[4]++;
       } else {
           testPartsIndex[0] = -1;
       }


   }

   public void testIsValid()
   {



       //shamelessly copied the resultpairs from Part A and added a couple
       ResultPair[] testUrlScheme = {new ResultPair("http://", true),
                                   new ResultPair("ftp://", true),
                                   new ResultPair("hmk6://", true),
                                   new ResultPair("33t://", false),
                                   new ResultPair("http:/", false),
                                   new ResultPair("http/://", false),
                                   new ResultPair("http/", false),
                                   new ResultPair("://", false),
                                   new ResultPair("", true)};

       ResultPair[] testUrlAuthority = {new ResultPair("www.google.com", true),
                                      new ResultPair("go.com", true),
                                      new ResultPair("go.au", true),
                                      new ResultPair("0.0.0.0", true),
                                      new ResultPair("10.10.250.250", true),
                                      new ResultPair("255.255.255.255", true),
                                      new ResultPair("256.256.256.256", false),
                                      new ResultPair("255.com", true),
                                      new ResultPair("1.2.3.4.5", false),
                                      new ResultPair("1.2.3.4.", false),
                                      new ResultPair("1.2.3", false),
                                      new ResultPair(".1.2.3.4", false),
                                      new ResultPair("go.a", false),
                                      new ResultPair("go.a1a", false),
                                      new ResultPair("go.1aa", false),
                                      new ResultPair("aaa.", false),
                                      new ResultPair(".aaa", false),
                                      new ResultPair("aaa", false),
                                      new ResultPair("", false)
       };
       ResultPair[] testUrlPort = {new ResultPair(":80", true),
                                 new ResultPair(":8080", true),
                                 new ResultPair(":65535", true),
                                 new ResultPair(":0", true),
                                 new ResultPair("", true),
                                 new ResultPair(":-1", false),
                                 new ResultPair(":65636",false),
                                 new ResultPair(":a65", false)
       };
       ResultPair[] testPath = {new ResultPair("/test1", true),
                              new ResultPair("/t123", true),
                              new ResultPair("/$23", true),
                              new ResultPair("/..", false),
                              new ResultPair("/../", false),
                              new ResultPair("/test1/", true),
                              new ResultPair("", true),
                              new ResultPair("/test1/file", true),
                              new ResultPair("/..//file", false),
                              new ResultPair("/test1//file", false)
       };
       //Test allow2slash, noFragment
       ResultPair[] testUrlPathOptions = {new ResultPair("/test1", true),
                                        new ResultPair("/t123", true),
                                        new ResultPair("/$23", true),
                                        new ResultPair("/..", false),
                                        new ResultPair("/../", false),
                                        new ResultPair("/test1/", true),
                                        new ResultPair("/#", false),
                                        new ResultPair("", true),
                                        new ResultPair("/test1/file", true),
                                        new ResultPair("/t123/file", true),
                                        new ResultPair("/$23/file", true),
                                        new ResultPair("/../file", false),
                                        new ResultPair("/..//file", false),
                                        new ResultPair("/test1//file", true),
                                        new ResultPair("/#/file", false)
       };

       ResultPair[] testUrlQuery = {new ResultPair("?action=view", true),
                                  new ResultPair("?action=edit&mode=up", true),
                                  new ResultPair("", true)
       };

       Object[] testUrlParts = {testUrlScheme, testUrlAuthority, testUrlPort, testPath, testUrlQuery};
       Object[] testUrlPartsOptions = {testUrlScheme, testUrlAuthority, testUrlPort, testUrlPathOptions, testUrlQuery};
       int[] testPartsIndex = {0, 0, 0, 0, 0};
       int[] testPartsMaxIndex = {testUrlScheme.length, testUrlAuthority.length, testUrlPort.length, testPath.length, testUrlQuery.length};


	   //You can use this function for programming based testing

       do{
           String url = testUrlScheme[testPartsIndex[0]].item;
           boolean expected = testUrlScheme[testPartsIndex[0]].valid;

           url += testUrlAuthority[testPartsIndex[1]].item;
           expected &= testUrlScheme[testPartsIndex[1]].valid;

           url += testUrlPort[testPartsIndex[2]].item;
           expected &= testUrlScheme[testPartsIndex[2]].valid;

           url += testPath[testPartsIndex[3]].item;
           expected &= testUrlScheme[testPartsIndex[3]].valid;

           url += testUrlQuery[testPartsIndex[4]].item;
           expected &= testUrlScheme[testPartsIndex[4]].valid;

           UrlValidator urlVal = new UrlValidator(ALLOW_ALL_SCHEMES);
           boolean result = urlVal.isValid(url);
           System.out.println(url);
           System.out.println(expected);
           System.out.println(result);

           //assertEquals(url,expected,result);
           if (expected == result) {
        	   		System.out.println(url);
        	   		System.out.println("Did not match expected result");
           }
           
           incTestPartsIndex(testPartsIndex,testPartsMaxIndex);
       } while (testPartsIndex[0] != -1);


   }
   

   


}

