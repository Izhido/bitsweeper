Public Class LogoForm

    Private TextRenderingHint As Drawing.Text.TextRenderingHint = Drawing.Text.TextRenderingHint.AntiAlias

    Private Sub LogoForm_KeyPress(ByVal sender As Object, ByVal e As System.Windows.Forms.KeyPressEventArgs) Handles Me.KeyPress

        If e.KeyChar = Chr(27) Then
            Close()
        ElseIf e.KeyChar = Chr(32) Then
            TextRenderingHint = TextRenderingHint + 1
            Invalidate()
        ElseIf e.KeyChar = "A"c Then
            TextRenderingHint = TextRenderingHint - 1
        End If

    End Sub

    Private Sub LogoForm_Paint(ByVal sender As Object, ByVal e As System.Windows.Forms.PaintEventArgs) Handles Me.Paint

        e.Graphics.FillRectangle(Brushes.Black, ClientRectangle)
        e.Graphics.ScaleTransform(0.58, 1.45)
        e.Graphics.RotateTransform(-5.5)
        e.Graphics.TranslateTransform(-3, 60)
        e.Graphics.TextRenderingHint = TextRenderingHint
        e.Graphics.DrawString("BITSWEEPER!", _
                              New Font("Stencil", 114), _
                              Brushes.White, _
                              New PointF(-2, 14))

    End Sub

End Class