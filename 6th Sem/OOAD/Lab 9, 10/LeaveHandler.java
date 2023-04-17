abstract class LeaveHandler {
    protected LeaveHandler nextHandler;

    public void setNextHandler(LeaveHandler handler) {
        this.nextHandler = handler;
    }

    public abstract void processRequest(LeaveRequest leave);
}
