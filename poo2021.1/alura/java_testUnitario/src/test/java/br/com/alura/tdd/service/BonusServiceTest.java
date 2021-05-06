package br.com.alura.tdd.service;

import static org.junit.jupiter.api.Assertions.assertEquals;

import java.math.BigDecimal;
import java.time.LocalDate;

import org.junit.jupiter.api.Test;

import br.com.alura.tdd.modelo.Funcionario;

public class BonusServiceTest {

    @Test
    void bonusDeveriaSerZeroParaFuncionarioComSalarioMuitoAlto() {

        BonusService service = new BonusService();
        BigDecimal bonus = service.calcularBonus(new Funcionario("Diogo", LocalDate.now(), new BigDecimal("25000")));

        assertEquals(new BigDecimal("0.00"), bonus);
    }

    @Test
    void bonusDeveriaSer10PorCentoDoSalario() {

        BonusService service = new BonusService();
        BigDecimal bonus = service.calcularBonus(new Funcionario("Diogo", LocalDate.now(), new BigDecimal("2000")));

        assertEquals(new BigDecimal("200.00"), bonus);

    }
}
