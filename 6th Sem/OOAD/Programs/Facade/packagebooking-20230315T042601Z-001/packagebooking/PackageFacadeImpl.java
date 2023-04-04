class PackageFacadeImpl implements PackageFacade
{
	@Override
	public void book() {
		 CabBooking cabbooking=new Cab();
		 cabbooking.book();
		 
		 HotelBooking hotelbooking=new Hotel();
		 hotelbooking.book();
		 
		 FlightBooking flightbooking=new Flight();
		 flightbooking.book();
		 System.out.println("Travel package booked successfully");
 } 

}