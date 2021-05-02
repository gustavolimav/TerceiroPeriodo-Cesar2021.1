package br.com.alura.tdd.service;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;
import static org.junit.jupiter.api.Assertions.fail;

import java.math.BigDecimal;
import java.time.LocalDate;
import java.time.LocalTime;

import org.junit.jupiter.api.Test;

import br.com.alura.tdd.modelo.Funcionario;
import jdk.vm.ci.meta.Local;

public class BonusServiceTest {
    
    @Test
    void bonusDeveriaSerZeroParaFuncionarioComSalarioMuitoAlto() {
        
        BonusService service = new BonusService();
        assertThrows(IllegalArgumentException.class ,() -> service.calcularBonus(new Funcionario
        ("Diogo", LocalDate.now(), new BigDecimal("25000"))));

    }

    @Test
    void bonusDeveriaSer10PorCentoDoSalario() {

        BonusService service = new BonusService();
        BigDecimal bonus = service.calcularBonus(new Funcionario
        ("Diogo", LocalDate.now(), new BigDecimal("2000")));
        
        assertEquals(new BigDecimal("200.00"), bonus);

    }
}
