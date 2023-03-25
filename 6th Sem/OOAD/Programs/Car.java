package Programs;

class Car {
    private String make;
    private String model;
    private int year;
    private int doors;
    private boolean hasSunroof;
    private String color;
    private String engine;

    private Car(CarBuilder builder) {
        this.make = builder.make;
        this.model = builder.model;
        this.year = builder.year;
        this.doors = builder.doors;
        this.hasSunroof = builder.hasSunroof;
        this.engine = builder.engine;
        this.color = builder.color;
    }

    public static class CarBuilder {
        private String make;
        private String model;
        private int year;
        private int doors;
        private boolean hasSunroof;
        private String color;
        private String engine;

        public CarBuilder(String make, String model, int year) {
            this.make = make;
            this.model = model;
            this.year = year;
        }

        public CarBuilder setDoors(int doors) {
            this.doors = doors;
            return this;
        }

        public CarBuilder setHasSunroof(boolean hasSunroof) {
            this.hasSunroof = hasSunroof;
            return this;
        }

        public CarBuilder setColor(String color) {
            this.color = color;
            return this;
        }

        public CarBuilder setEngine(String engine) {
            this.engine = engine;
            return this;
        }

        public Car build() {
            return new Car(this);
        }

    }

    public static void main(String[] args) {
        Car car = new Car.CarBuilder("Honda", "City", 2015).setDoors(4).setHasSunroof(true).setColor("Red")
                .setEngine("V6").build();
        System.out.println(car.make + " " + car.model + " " + car.year + " " + car.doors + " " + car.hasSunroof + " "
                + car.color + " " + car.engine);
    }
}
