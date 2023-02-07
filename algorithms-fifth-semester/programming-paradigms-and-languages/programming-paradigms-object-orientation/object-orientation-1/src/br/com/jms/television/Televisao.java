package br.com.jms.television;

class Televisao {
    Integer canal;
    Integer volume;

    public Televisao() {
        this.volume = 0;
    }

    public Integer getVolume() {
        return volume;
    }

    public Integer getCanal() {
        return canal;
    }

    public void setVolume(int volume) {
        this.volume = volume;
    }

    public void setCanal(int canal) {
        this.canal = canal;
    }

    public void aumentarVolume() {
        setVolume(getVolume() + 1);
    }

    public void diminuirVolume() {
        setVolume(getVolume() - 1);
    }

    public void alterarCanal(int canal) {
        setCanal(canal);
    }
}
