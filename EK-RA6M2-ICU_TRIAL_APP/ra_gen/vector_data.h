/* generated vector header file - do not edit */
#ifndef VECTOR_DATA_H
#define VECTOR_DATA_H
#ifdef __cplusplus
        extern "C" {
        #endif
/* Number of interrupts allocated */
#ifndef VECTOR_DATA_IRQ_COUNT
#define VECTOR_DATA_IRQ_COUNT    (1)
#endif
/* ISR prototypes */
void MY_EVENT(void);

/* Vector table allocations */
#define VECTOR_NUMBER_ICU_IRQ3 ((IRQn_Type) 0) /* ICU IRQ3 (External pin interrupt 3) */
#define ICU_IRQ3_IRQn          ((IRQn_Type) 0) /* ICU IRQ3 (External pin interrupt 3) */
#ifdef __cplusplus
        }
        #endif
#endif /* VECTOR_DATA_H */
