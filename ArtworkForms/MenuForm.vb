Public Class MenuForm

    Private TextRenderingHint As Drawing.Text.TextRenderingHint = Drawing.Text.TextRenderingHint.AntiAlias

    Private Sub MenuForm_KeyPress(ByVal sender As Object, ByVal e As System.Windows.Forms.KeyPressEventArgs) Handles Me.KeyPress

        If e.KeyChar = Chr(27) Then
            Close()
        ElseIf e.KeyChar = "t"c Then
            TextRenderingHint = TextRenderingHint + 1
            Invalidate()
        ElseIf e.KeyChar = "A"c Then
            TextRenderingHint = TextRenderingHint - 1
        End If

    End Sub

    Private Sub LogoForm_KeyPress(ByVal sender As Object, ByVal e As System.Windows.Forms.KeyPressEventArgs) Handles Me.KeyPress

        If e.KeyChar = Chr(27) Then
            Close()
        End If

    End Sub

End Class
